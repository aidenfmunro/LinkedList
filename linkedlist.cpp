#include <stdlib.h>
#include "utils.h"
#include "linkedlist.h"

const int FREE_ELEM = -1;

const int DEFAULT_LIST_CAPACITY = 4;

const int HEAD_AND_TAIL = 2;

const int MAX_LIST_CAPACITY = 1024;

const ListElem_t FREE_HEAD = -1;

enum ERRORS
{   
    OK,
    NO_MEMORY_AVAILABLE,
    INDEX_OUT_OF_RANGE
};

ErrorCode createList(List* list)
{
    SafeCalloc(list->head, Node, DEFAULT_LIST_CAPACITY + HEAD_AND_TAIL);

    list->data = &list->head[1];

    list->tail = &list->data[DEFAULT_LIST_CAPACITY];

    list->capacity = DEFAULT_LIST_CAPACITY;

    list->size = 0;
    list->freeHead = 0;

    for (size_t i = 0; i < DEFAULT_LIST_CAPACITY; i++)
        list->data[i].value = FREE_ELEM;
    
    list->head->prev = NULL;
    list->tail->next = NULL;

    return OK;
}

ErrorCode insertToFront(List* list, ListElem_t value, size_t index)
{
    AssertSoft(0 <= index < list->size, INDEX_OUT_OF_RANGE);

    list->size += 1;

    /* realloc check */

    list->data[list->freeHead].value = value;

    Node* tempNode = list->data[index].next;

    tempNode->prev         = &list->data[list->freeHead];
    list->data[index].next = &list->data[list->freeHead];

    list->data[list->freeHead].next = tempNode;
    list->data[list->freeHead].prev = &list->data[index];

    list->freeHead += 1;
    
    return OK;
}

ErrorCode insertToBack(List* list, ListElem_t value, size_t index)
{
    AssertSoft(0 <= index < list->size, INDEX_OUT_OF_RANGE);

    list->size += 1;

    /* realloc check */

    list->data[list->freeHead].value = value;

    Node* tempNode = list->data[index].prev;

    tempNode->next         = &list->data[list->freeHead];
    list->data[index].prev = &list->data[list->freeHead];

    list->data[list->freeHead].prev = tempNode;
    list->data[list->freeHead].next = &list->data[index];

    
    list->freeHead += 1;

    return OK;
}

ErrorCode pushFront(List* list, ListElem_t value)
{

}


ErrorCode pushBack(List* list, ListElem_t value)
{
    list->size += 1;

    list->data[list->freeHead].value = value;

    list->data[list->freeHead].prev = list->head;
    list->data[list->freeHead].next = list->head->next;

    list->head->next = &list->data[list->freeHead];
    list->data->prev = &list->data[list->freeHead];

    list->freeHead += 1;
}

ErrorCode listVerify(List* list)
{

}

ErrorCode printList(List* list)
{

    printf("values stored physically:\n{\n");
    
    for (size_t i = 0; i < list->size; i++)
    {
        printf("\t[%llu]: %d\n", i, list->data[i].value);
    }

    printf("}\n\n");

    Node* curNode = list->head->next;

    printf("values stored with nodes:\n{\n");

    for (size_t i = 0; i < list->size; i++)
    {
        printf("\t[%llu]: %d\n", i, curNode->value);
        curNode = curNode->next;
    }

    printf("}\n");

    return OK;
}




