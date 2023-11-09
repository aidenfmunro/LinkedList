#include "linkedlist.h"

int main(int argc, char* argv[])
{
    List list = {};
    createList(&list);
    // pushBack(&list, 10);
    // pushBack(&list, 20);
    // pushBack(&list, 30);
    // pushBack(&list, 40);
    insertAfter(&list, 0, 20);
    insertAfter(&list, 0, 30);
    insertAfter(&list, 0, 40);
    insertAfter(&list, 2, 60);
    insertAfter(&list, 1, 70);

    printList(&list);
    DumpListGraph(&list);
}