#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    Node* next;
};

Node* head = NULL;

int main(int argc, char* argv[])
{

    return 0;
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
      }
    
    Node* 
}