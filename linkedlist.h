#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef int Elem_t; 

struct ListElem_t
{
    Elem_t value;

    size_t next;
    size_t prev;
};

struct List
{
    ListElem_t* ptr;

    size_t size;
    size_t capacity;
    size_t freeHead;

    size_t head;
    size_t tail;
};

ErrorCode CreateList(List* list);

ErrorCode DestroyList(List* list);

ErrorCode PushFront(List* list, Elem_t value);

ErrorCode PushBack(List* list, Elem_t value);

ErrorCode InsertAfter(List* list, size_t index, Elem_t value);

ErrorCode InsertBefore(List* list, size_t index, Elem_t value);

ErrorCode reallocList(List* list);

ErrorCode Delete(List* list, size_t index);

ErrorCode PrintList(List* list);

ErrorCode DumpListGraph(List* list);

ErrorCode listVerify(List* list);

#endif