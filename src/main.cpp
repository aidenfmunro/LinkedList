// #include "linkedlistptr.h"

#include "linkedlist.h"

int main(void)
{
    List list = {};
    
    CreateList(&list);
    
    PushFront(&list, 30);
    PushFront(&list, 40);
    InsertAfter(&list, 0, 60);
    InsertAfter(&list, 1, 70);
    InsertAfter(&list, 2, 80);
    PushFront(&list, 90);
    PushBack(&list, 70);
    PushBack(&list, 100);
    PrintList(&list);
    PushBack(&list, 110);
    DumpListGraph(&list);
    
    DestroyList(&list);

    //List list = {};
    //
    //CreateList(&list);
    //
    //PushFront(&list, 10);
    //
    //PushFront(&list, 20);
    //
    //InsertAfter(list.head, 30);
    //
    //InsertBefore(list.head->next, 40);
    //
    //PushBack(&list, 50);
    //
    //PrintList(&list);
    //
    //Pop(list.head->next);
    //
    //PrintList(&list);
    //
    //DumpListGraph(&list);   
    //
    //DestroyList(&list);

}