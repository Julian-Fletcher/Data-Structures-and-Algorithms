#include "linked_list_oh.h"

// Create user list variable
List createList(){
    List list;
    list.listHead = new(Node);
    list.listHead->next = nullptr;
    list.listSize = 0;

    return list;
}

// Return the size of the list
int getListSize(List list){
    return list.listSize;
}

// Insert a new data item at the head of the list
void insertAtHead(List list, float data){
    if(list.listHead == nullptr){
        std::cout << "Initialize your list first!" << std::endl;
    }
    Node *newNode = new(Node);
    newNode->data = data;

    // Insert at head of list
    newNode->next = list.listHead->next;
    list.listHead->next = newNode;
    list.listSize++;
}

// Removes desired item from the list, returns false if item not found
bool deleteItem(List list, float key){
    Node *traversalPtr = list.listHead->next;
    Node *trailingPtr = list.listHead->next;

    while(traversalPtr->next != nullptr){
        if(traversalPtr->data == key){
            trailingPtr->next = traversalPtr->next;
            delete(traversalPtr);
            return true;
        }
        trailingPtr = traversalPtr;
        traversalPtr = traversalPtr->next;
    }
    // Return false if the node is not found
    return false;
}

// Deletes the list
void freeList(List list){
    Node *traversalPtr = list.listHead;
    Node *trailingPtr = list.listHead;

    while(traversalPtr != nullptr){
        traversalPtr = traversalPtr->next;
        delete(trailingPtr);
        trailingPtr = traversalPtr;
    }
}
// Prints the items in the list
void printList(List list){
    Node *p = list.listHead->next;
    int count = 1;
    // Traverse and print
    while(p != nullptr){
        std::cout << "Data item in position " << count << " is " << std::setprecision(3) << p->data << std::endl;
        p = p->next;
        count++;
    }

}