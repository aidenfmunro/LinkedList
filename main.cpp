#include "linkedlist.h"

int main(int argc, char* argv[])
{
    List list = {};
    CreateList(&list);
    // pushBack(&list, 10);
    // pushBack(&list, 20);
    // pushBack(&list, 30);
    // pushBack(&list, 40);
    InsertAfter(&list, 0, 20);
    InsertAfter(&list, 0, 30);
    InsertAfter(&list, 0, 40);
    InsertAfter(&list, 2, 60);
    InsertAfter(&list, 1, 70);
    InsertAfter(&list, 3, 80);
    PushFront(&list, 49);
    PushBack(&list, 69);

    PrintList(&list);
    DumpListGraph(&list);
}