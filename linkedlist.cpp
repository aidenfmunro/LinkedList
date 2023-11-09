#include <stdlib.h>
#include "utils.h"
#include "linkedlist.h"

const size_t FREE_ELEM = -1;

const Elem_t POISON = __INT64_MAX__;

const int DEFAULT_LIST_CAPACITY = 8;

const int MAX_LIST_CAPACITY = 1024;

const size_t FREE_HEAD = -1;

enum ERRORS
{   
    OK,
    NO_MEMORY_AVAILABLE,
    INDEX_OUT_OF_RANGE,
    HEAD_PREV_IS_NULL,
    TAIL_NEXT_IS_NULL,
    UNABLE_TO_OPEN_FILE
};

ErrorCode createList(List* list)
{
    SafeCalloc(tempPtr, ListElem_t, DEFAULT_LIST_CAPACITY);

    list->ptr = tempPtr;

    list->size = 0;

    list->capacity = DEFAULT_LIST_CAPACITY;

    for (size_t i = 0; i < DEFAULT_LIST_CAPACITY; i++)
    {
        list->ptr[i] = {.value = POISON, .next = i + 1, .prev = FREE_ELEM};
    }

    list->freeHead = 0;

    list->ptr[list->freeHead].next = 1;
    list->ptr[list->freeHead].prev = 0;

    return OK;
}

ErrorCode pushFront(List* list, Elem_t value)
{
    return insertAfter(list, list->ptr[0].prev, value);
}

ErrorCode pushBack(List* list, Elem_t value)
{
    return insertAfter(list, list->ptr[list->size].next, value);
}

ErrorCode insertBefore(List* list, size_t index, Elem_t value)
{
    return insertAfter(list, list->ptr[index].prev, value);
}

ErrorCode insertAfter(List* list, size_t index, Elem_t value)
{
    size_t newNext = list->ptr[index].next; // assign index of next elem in index;

    size_t curFreeIndex = list->freeHead; // where the new elem is storred

    list->freeHead = list->ptr[curFreeIndex].next; //

    list->ptr[curFreeIndex].value = value;

    list->ptr[curFreeIndex].next = newNext;

    list->ptr[curFreeIndex].prev = index;

    list->ptr[index].next = curFreeIndex;

    list->ptr[newNext].prev = curFreeIndex;

    list->size++;

    /* realloc */

    return OK;
}

ErrorCode DeleteElem(List* list, size_t index)
{

}

ErrorCode printList(List* list)
{
    printf("physical address: \n");

    for (size_t i = 0; i < list->capacity; i++)
    {
        printf("[%llu] -> value: %d, next: %llu, prev %llu\n", i, list->ptr[i].value, list->ptr[i].next, list->ptr[i].prev);
    }

    printf("\nin order:\n");
    size_t curIndex = list->ptr[0].next;

    for (size_t i = 0; i < list->size; i++)
    {
        printf("[%llu] -> value: %d, next: %llu, prev %llu\n", curIndex, list->ptr[curIndex].value, list->ptr[curIndex].next, list->ptr[curIndex].prev);
        curIndex = list->ptr[curIndex].next;
    }
}

#define GRAPH_DUMP_FILENAME "GraphDump.dot"

#define FONT_SIZE "10"

#define FONT_NAME "helvetica"

#define NODE_FRAME_COLOR "\"#fffdd0\""

#define BACKGROUND_COLOR "\"#ffffff\""

#define FREE_HEAD_COLOR "\"#b9e793\""

#define NODE_COLOR "\"#fffdd0\""

#define dumpGraph(filename, ...) fprintf(filename, __VA_ARGS__)

ErrorCode DumpListGraph(List* list)
{
    myOpen(GRAPH_DUMP_FILENAME, "w", graphFile);

    dumpGraph(graphFile,
    "digraph\n"
    "{\n"
    "rankdir = LR;\n"
    "node [shape = record, color = " NODE_FRAME_COLOR ", fontname = " FONT_NAME ", fontsize = " FONT_SIZE "];\n"
    "bgcolor = " BACKGROUND_COLOR ";\n"
    );

    for (size_t i = 0; i < list->capacity; i++)
    {
        dumpGraph(graphFile,
        "NODE_%zu[style = \"filled\", fillcolor = " NODE_COLOR ", "
        "label = \"index = %d|value\\n%d|{prev = %d|next = %d}\"];\n",
        i, i, list->ptr[i].value, list->ptr[i].prev, list->ptr[i].next
        );
    }

    dumpGraph(graphFile, "NODE_0");

    for (size_t i = 1; i < list->capacity; i++)
    {
        dumpGraph(graphFile, "->NODE_%zu", i);
    }
    
    dumpGraph(graphFile, ";\n"
    "}\n"
    );

    myClose(graphFile);

    return OK;
}





