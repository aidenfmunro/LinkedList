#include "linkedlistptr.h"

Node* initNode(Elem_t value);

ErrorCode destroyNode(Node* node);

ErrorCode CreateList(List* list)
{
    AssertSoft(list, NULL_PTR);

    list->head = NULL;

    list->tail = NULL;

    return OK;
}

ErrorCode DestroyList(List* list)
{
    AssertSoft(list, NULL_PTR);

    Node* curNode  = list->head->next;
    Node* tempNode = NULL;

    while (curNode)
    {
        tempNode = curNode->next;

        destroyNode(curNode);

        curNode = tempNode;
    }

    list->head = NULL;
    list->tail = NULL;

    return OK;
}

ErrorCode PrintList(List* list)
{
    AssertSoft(list, NULL_PTR);

    Node* curNode = list->head;
    size_t index = 1;

    printf("Linked List:\n{\n");

    while (curNode)
    {
        printf("\t[%lu]: "SPECIFIER" \n", index, curNode->value);

        curNode = curNode->next;
    }

    printf("}\n");

    return OK;
}

ErrorCode destroyNode(Node* node)
{
    AssertSoft(node, NULL_PTR);

    node->value = POISON;
    node->next = NULL;
    node->prev = NULL;

    free(node);

    return OK;
}

Elem_t Pop(Node* node)
{
    AssertSoft(node, NULL_PTR);

    Elem_t value = node->value;

    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;

    return destroyNode(node);
}


Node* PushFront(List* list, Elem_t value)
{
    AssertSoft(list, NULL);

    Node* newNode = initNode(value);

    AssertSoft(newNode, NULL);

    if (! list->head && ! list->tail)
    {
        newNode->value = value;

        list->head = newNode;
        list->tail = newNode;

        return newNode;
    }

    Node* oldHead = list->head;

    list->head = newNode;

    newNode->value = value;

    newNode->prev = NULL;
    newNode->next = oldHead;

    oldHead->prev = newNode;

    return newNode;
}

Node* PushBack(List* list, Elem_t value)
{
    AssertSoft(list, NULL);

    Node* newNode = initNode(value);

    AssertSoft(newNode, NULL);

    if (! list->head && ! list->tail)
    {
        list->head = newNode;
        list->tail = newNode;
        
        return newNode;
    }

    Node* oldTail = list->tail;

    list->tail = newNode;

    newNode->next = NULL;
    newNode->prev = oldTail;

    oldTail->next = newNode;

    return newNode;
}

Node* InsertAfter(Node* node, Elem_t value)
{
    AssertSoft(node, NULL);

    Node* newNode = initNode(value);

    AssertSoft(newNode, NULL);

    newNode->next = node->next;
    newNode->prev = node;

    node->next->prev = newNode;
    node->next = newNode;

    return newNode;
}

Node* initNode(Elem_t value)
{
    SafeCalloc(tempNode, Node, 1, NULL);

    tempNode->value = value;

    tempNode->next = NULL;
    tempNode->prev = NULL;

    return tempNode;
}

Node* InsertBefore(Node* node, Elem_t value)
{
    AssertSoft(node, NULL);

    return InsertAfter(node->prev, value);
}