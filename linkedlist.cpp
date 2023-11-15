#include "linkedlist.h"

// TD: linearization

ErrorCode CreateList(List* list)
{
    AssertSoft(list, NULL_PTR);

    SafeCalloc(tempPtr, ListElem_t, DEFAULT_LIST_CAPACITY, NO_MEMORY_AVAILABLE);

    list->ptr = tempPtr;

    list->size = 1;

    list->capacity = DEFAULT_LIST_CAPACITY;


    // TD: fill_range()
    // DSL: add_to_free
    for (size_t i = 0; i < DEFAULT_LIST_CAPACITY; i++)
    {
        list->ptr[i].value = POISON;
    }

    for (size_t i = 1; i < DEFAULT_LIST_CAPACITY - 1; i++)
    {
        list->ptr[i].next = i + 1;
    }

    for (size_t i = 1; i < DEFAULT_LIST_CAPACITY; i++)
    {
        list->ptr[i].prev = FREE_ELEM;
    }

    list->freeHead = 1;

    list->head = list->ptr[0].next;
    list->tail = list->ptr[0].prev; // TD: sensiel

    return OK;
}

ErrorCode DestroyList(List* list) // TODO: fill with poison value 
{
    AssertSoft(list, NULL_PTR);

    free(list->ptr);

    return OK;
}

#define CHECK_VERIFICATION(error)       \
    if (error)                          \
    {                                   \
        return error;                   \
    }

ErrorCode InsertAfter(List* list, size_t index, Elem_t value)
{
    CHECK_VERIFICATION(listVerify(list));

    list->size++;

    if (list->size > list->capacity)
    {
       reallocList(list); 
    }

    // TD: DSL - CONNECT_NODES(node1, node2)
    size_t insertIndex = list->freeHead; 

    list->freeHead = list->ptr[insertIndex].next; 

    list->ptr[insertIndex].value = value;

    list->ptr[insertIndex].prev = index;
    list->ptr[insertIndex].next = list->ptr[index].next; // NEXT(index)

    list->ptr[list->ptr[index].next].prev = insertIndex;
    list->ptr[index].next = insertIndex;

    CHECK_VERIFICATION(listVerify(list));

    return OK;
}

#undef CHECK_VERIFICATION

ErrorCode InsertBefore(List* list, size_t index, Elem_t value)
{
    return InsertAfter(list, list->ptr[index].prev, value);
}

ErrorCode PushFront(List* list, Elem_t value)
{
    return InsertAfter(list, list->head, value);
}

ErrorCode PushBack(List* list, Elem_t value)
{
    return InsertBefore(list, list->tail, value); 
}

Elem_t Pop(List* list, size_t index)
{
    AssertSoft(index < list->size, INDEX_OUT_OF_RANGE);

    Elem_t value   = list->ptr[index].value;
    size_t delPrev = list->ptr[index].prev;
    size_t delNext = list->ptr[index].next;

    size_t curFree = list->freeHead;

    list->ptr[curFree].next = index;

    list->freeHead = index;

    list->ptr[index].value = POISON;

    list->ptr[index].next = curFree;

    list->ptr[index].prev = FREE_ELEM;

    list->ptr[delPrev].next = delNext;

    list->ptr[delNext].prev = delPrev;

    list->size--;

    return value;
}

ErrorCode reallocList(List* list)
{
    SafeRealloc(tempPtr, ListElem_t, list->ptr, list->capacity * 2 * sizeof(ListElem_t));

    list->ptr = tempPtr;

    for (size_t i = list->capacity; i < list->capacity * 2 - 1; i++)
    {
        list->ptr[i].next = i + 1;
    }

    for (size_t i = list->capacity; i < list->capacity * 2; i++)
    {
        list->ptr[i].value = POISON;
        list->ptr[i].prev = FREE_ELEM;
    }
    
    list->ptr[list->capacity * 2 - 1].next = 0; // TD: harcode 

    list->freeHead = list->capacity;

    list->capacity = list->capacity * 2;

    return OK;
}

ErrorCode PrintList(List* list)
{
    printf("physical address: \n");

    for (size_t i = 0; i < list->capacity; i++)
    {
        printf("[%lu] -> value: %d, next: %lu, prev %lu\n", i, list->ptr[i].value, list->ptr[i].next, list->ptr[i].prev);
    }

    printf("\nin order:\n");

    size_t curIndex = list->head;

    for (size_t i = 0; i < list->size; i++)
    {
        printf("[%lu] -> value: %d, next: %lu, prev %lu\n", curIndex, list->ptr[curIndex].value, list->ptr[curIndex].next, list->ptr[curIndex].prev);
        curIndex = list->ptr[curIndex].next;
    }

    return OK;
}

#define CHECK_ERROR(EXPRESSION, ERROR)                  \
    if (EXPRESSION)                                     \
    {                                                   \
        return ERROR;                                   \
    }                


ErrorCode listVerify(List* list)
{
    CHECK_ERROR(!list, NULL_PTR);
    CHECK_ERROR(!list->ptr, NULL_PTR);
    CHECK_ERROR(list->size > list->capacity, LIST_OVERFLOW);
    CHECK_ERROR(list->capacity > MAX_LIST_CAPACITY, LIST_OVERFLOW);
    CHECK_ERROR(list->freeHead > list->capacity - 1, FREEHEAD_FUCKED_UP);

    // TD: loop?

    return OK;
}

#undef CHECK_ERROR

#define GRAPH_DUMP_FILENAME "GraphDump.dot"

#define FONT_SIZE "10"

#define FONT_NAME "helvetica"

#define NODE_FRAME_COLOR "\"#fffdd0\""

#define BACKGROUND_COLOR "\"#ffffff\""

#define FREE_HEAD_COLOR "\"#b9e793\""

#define NODE_COLOR "\"#fffdd0\""

#define ROOT_COLOR "\"#ff0000\""

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
    "ROOT[style = \"filled\", fillcolor = " ROOT_COLOR ", "
    "label = \"ROOT|{<head>head = %zu|<tail>tail = %zu}\"];\n",
    list->ptr[0].next, list->ptr[0].prev
    );

    for (size_t i = 1; i < list->capacity; i++)
    {
        dumpGraph(graphFile,
        "NODE_%zu[style = \"filled\", fillcolor = " NODE_COLOR ", "
        "label = \"index = %lu|value\\n%d|{prev = %lu|next = %lu}\"];\n",
        i, i, list->ptr[i].value, list->ptr[i].prev, list->ptr[i].next
        );
    }

    dumpGraph(graphFile, "ROOT");

    for (size_t i = 1; i < list->capacity; i++)
    {
        dumpGraph(graphFile, "->NODE_%zu", i);
    }

    dumpGraph(graphFile, " [weight = 100000, color = " BACKGROUND_COLOR "];\n");

    dumpGraph(graphFile, "ROOT:head");

    size_t nodePointer = list->ptr[0].next;

    for (size_t i = 1; i < list->size; i++)
    {
        dumpGraph(graphFile, "->NODE_%zu", nodePointer);

        nodePointer = list->ptr[nodePointer].next;
    }

    dumpGraph(graphFile, "->ROOT:tail");
    
    dumpGraph(graphFile, ";\n"
    "}\n"
    );

    myClose(graphFile);

    return OK;
}





