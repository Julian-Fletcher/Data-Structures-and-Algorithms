#include <iostream>
#include <iomanip>

typedef struct node{
    double data;
    node *prev;
    node *next;
}Node;

typedef struct list{
    Node *dummyHead;
    int *size;
}List;


List createList();
int getListSize(List list);
bool insertAtHead(List list, float data);
bool deleteItem(List list, float key);
void freeList(List list);
void printList(List list);