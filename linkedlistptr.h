#ifndef LINKEDLISTPTR_H
#define LINKEDLISTPTR_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef int Elem_t;

const Elem_t POISON = __INT32_MAX__;

#define SPECIFIER "%d"

struct Node
{
    Elem_t value;

    Node*  next;
    Node*  prev;  
};

struct List
{
    Node*  head;
    Node*  tail;
};

ErrorCode CreateList(List* list);

ErrorCode DestroyList(List* list);

ErrorCode PrintList(List* list);

Node*     PushFront(List* list, Elem_t value);

Node*     PushBack(List* list, Elem_t value);

Node*     InsertAfter(Node* node, Elem_t value);

Node*     InsertBefore(Node* node, Elem_t value);

Node*     FindElement(List* list, size_t index);

Elem_t    Pop(Node* node);

#endif