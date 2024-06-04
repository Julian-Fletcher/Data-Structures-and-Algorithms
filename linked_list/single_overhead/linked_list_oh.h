#ifndef SINGLE_OVERHEAD_LINKED_LIST_H
#define SINGLE_OVERHEAD_LINKED_LIST_H

#endif //SINGLE_OVERHEAD_LINKED_LIST_H

#include <iostream>

typedef struct _node{
    void *data;
    struct _node *next;
}Node;

typedef struct wrapper{
    Node *listHead;
    int listSize;
}List;

List createList();
int getListSize(List list);
void insertAtHead(List list, void *data);
bool deleteItem(List list, void *key, int (*comp_func)(void *a, void *b));
bool freeList(List list);
void printList(List list, std::string(*print_func)(void *data));