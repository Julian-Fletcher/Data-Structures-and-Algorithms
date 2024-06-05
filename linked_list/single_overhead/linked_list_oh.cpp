#include "linked_list_oh.h"


List createList(){
    List list;
    list.listHead = new(Node);
    list.listHead->next = nullptr;
    list.listSize = 0;

    return list;
}

int getListSize(List list){
    return list.listSize;
}

void insertAtHead(List list, float data){
    Node *newNode = new(Node);
    newNode->data = data;

    // Insert at head of list
    newNode->next = list.listHead->next;
    list.listHead->next = newNode;

}

bool deleteItem(List list, float key){
    Node *traversalPtr = list.listHead;
    Node *trailingPtr = list.listHead;

    while(traversalPtr->next != nullptr){
        if(traversalPtr->data == key){
            trailingPtr->next = traversalPtr->next;
            delete(traversalPtr);
            return true;
        }
    }
    // Return false if the node is not found
    return false;
}

void freeList(List list){
    Node *traversalPtr = list.listHead;
    Node *trailingPtr = list.listHead;

    while(traversalPtr->next != nullptr){
        traversalPtr = traversalPtr->next;
        delete(trailingPtr);
        trailingPtr = traversalPtr;
    }
}
void printList(List list);