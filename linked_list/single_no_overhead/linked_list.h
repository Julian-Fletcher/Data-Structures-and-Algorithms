
#ifndef SINGLE_NO_OVERHEAD_LINKED_LIST_H
#define SINGLE_NO_OVERHEAD_LINKED_LIST_H

#endif //SINGLE_NO_OVERHEAD_LINKED_LIST_H


#include <iostream>

typedef struct _node{
    void *data;
    struct _node *next;
}Node;

Node * createList();
Node * getListSize(Node *head);
Node * insertAtHead(Node *head, void *data);
void * deleteItem(Node *head, void *key);
Node * freeList();
