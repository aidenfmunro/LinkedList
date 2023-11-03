#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    
    Node* next;
};

struct List
{
    Node* head;

    Node* next;

    size_t count;
};


typedef int ErrorCode;

Node* insertNode(int data, int position);

Node* addNode(int data);

int removeNode(int data);

Node* head = NULL;

int main(int argc, char* argv[])
{
    addNode(1);
    addNode(2);
    addNode(3);
    insertNode(5, 2);
    Node* curNode = head;
    for (size_t i = 0; i < 4; i++)
      {
        printf("[%d], %d\n", i, curNode->data);
        curNode = curNode->next;
      }
    return 0;
}

List* CreateList(void)
{
  List* list = {};
  list->head = NULL;  
}

Node* addNode(int data) // O(n) at first sight? -> just add to head :D
{
    Node* newhead = (Node*)calloc(1, sizeof(Node)); if (!newhead) return NULL;

    newhead->data = data;

    if (!head) newhead->next = NULL; else newhead->next = head;

    head = newhead;
    
    return newhead;

}

int removeNode(int data)
{
    Node* curNode = head;
    Node* prevNode = head;
    
    while (!curNode)
      {
        if (curNode->data = data)
          {
            if (curNode == head)
              {
                head = curNode->next;
              }
            else
              {
                prevNode->next = curNode->next;

                free(curNode);
                curNode = NULL;
              }
            
            return 1;
          }
        prevNode = curNode;
        curNode = curNode->next;
      }
    
    return 0;
}

Node* insertNode(int data, int position)
{
    Node* curNode = head;

    while (curNode && position != 0)
      {
        position--;
        curNode = curNode->next;
      }
    
    Node* newNode = (Node*)calloc(1, sizeof(Node));

    newNode->data = data;
    newNode->next = curNode->next;
    curNode->next = newNode;
}