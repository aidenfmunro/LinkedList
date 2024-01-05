// #include "linkedlistptr.h"

#include "linkedlist.h"

int main(void)
{
    List list = {};
    
    CreateList(&list);
    
    PushFront(&list, 30);
    Remove(&list, 1);
    PrintList(&list);
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