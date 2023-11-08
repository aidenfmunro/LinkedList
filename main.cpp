#include "linkedlist.h"

int main(int argc, char* argv[])
{
    List list = {};
    createList(&list);
    pushBack(&list, 10);
    pushBack(&list, 20);
    pushBack(&list, 30);
    pushBack(&list, 40);
    insertToFront(&list, 5, 2);
    printList(&list);
}