#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ErrorCode;

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
};

ErrorCode createList(List* list);

ErrorCode pushFront(List* list, Elem_t value);

ErrorCode pushBack(List* list, Elem_t value);

ErrorCode insertAfter(List* list, size_t index, Elem_t value);

ErrorCode insertBefore(List* list, size_t index, Elem_t value);

ErrorCode printList(List* list);

#endif