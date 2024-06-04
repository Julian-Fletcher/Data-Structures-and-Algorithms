
#ifndef SINGLE_NO_OVERHEAD_LINKED_LIST_H
#define SINGLE_NO_OVERHEAD_LINKED_LIST_H

#endif //SINGLE_NO_OVERHEAD_LINKED_LIST_H


#include <iostream>

typedef struct _node{
    void *data;
    struct _node *next;
}Node;

Node * createList(void *data);
int getListSize(Node *head);
Node * insertAtHead(Node *head, void *data);
void * deleteItem(Node *head, void *key, int (*comp_func)(void *a, void *b));
Node * freeList(Node *head);
void printList(Node *head, std::string(*print_func)(void *data));