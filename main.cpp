#include "linkedlistptr.h"

int main(int argc, char* argv[])
{
    //List list = {};
    //
    //CreateList(&list);
    //
    //InsertAfter(&list, 0, 20);
    //InsertAfter(&list, 0, 30);
    //InsertAfter(&list, 0, 40);
    //InsertAfter(&list, 2, 60);
    //InsertAfter(&list, 1, 70);
    //InsertAfter(&list, 3, 80);
    //InsertAfter(&list, 4, 90);
    //PrintList(&list);
    //
    //DestroyList(&list);

    List list = {};

    CreateList(&list);

    PushFront(&list, 10);

    PushFront(&list, 20);

    InsertAfter(list.head, 30);

    InsertBefore(list.head->next, 40);

    PushBack(&list, 50);

    PrintList(&list);

    Pop(list.head->next);

    PrintList(&list);

    DestroyList(&list);
}