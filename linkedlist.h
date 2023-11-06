#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ErrorCode;

typedef int ListElem_t;

struct Node
{
    ListElem_t value;

    Node* next;
    Node* prev;
};

struct List
{
    Node* head;

    Node* data;    

    Node* tail;

    int freeHead;

    int capacity;
    int size;
};

ErrorCode createList(List* list);
ErrorCode insertToFront(List* list, ListElem_t value, size_t index);
ErrorCode insertToBack(List* list, ListElem_t value, size_t index);
ErrorCode pushFront(List* list, ListElem_t value);
ErrorCode pushBack(List* list, ListElem_t value);
ErrorCode printList(List* list);

#endif