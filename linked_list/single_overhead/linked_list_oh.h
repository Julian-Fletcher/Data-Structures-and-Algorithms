#ifndef SINGLE_OVERHEAD_LINKED_LIST_H
#define SINGLE_OVERHEAD_LINKED_LIST_H

#endif //SINGLE_OVERHEAD_LINKED_LIST_H

#include <iostream>
#include <iomanip>

typedef struct _node{
    float data;
    struct _node *next;
}Node;

typedef struct wrapper{
    Node *listHead;
    int listSize;
}List;

List createList();
int getListSize(List list);
void insertAtHead(List list, float data);
bool deleteItem(List list, float key);
void freeList(List list);
void printList(List list);