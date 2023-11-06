#include "linkedlist.h"

int main(int argc, char* argv[])
{
    List list = {};
    createList(&list);
    pushBack(&list, 10);
    pushBack(&list, 20);
    printList(&list);
}