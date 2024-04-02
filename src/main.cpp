// #include "linkedlistptr.h"

#include "linkedlist.h"

int main(void)
{
    List list = {};
    
    CreateList(&list);
    
    PushFront(&list, 30);
    PushFront(&list, 20);
    PushFront(&list, 15);
    PushBack(&list, 12);
    PrintList(&list);
    DumpListGraph(&list);
    
    DestroyList(&list);

}