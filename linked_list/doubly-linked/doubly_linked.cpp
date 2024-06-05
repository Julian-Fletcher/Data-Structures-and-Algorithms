#include "doubly_linked.h"


List createList(){
    List list;
    list.dummyHead = new(Node);
    list.dummyHead->next = nullptr;
    list.dummyHead->prev = nullptr;     // Never to be set
    
    list.size = new(int);
    *(list.size) = 0;

    return list;
}


int getListSize(List list){
    return *(list.size);
}

bool insertAtHead(List list, float data){
    if(list.dummyHead == nullptr){
        return false;
    }
    
    Node *newNode = new(Node);
    newNode->data = data;
    newNode->prev = list.dummyHead;
    newNode->next = list.dummyHead->next;

    list.dummyHead->next = newNode;
    *(list.size)++;
    return true;    
}


bool deleteItem(List list, float key){
    Node *searchPtr = list.dummyHead->next;
    Node *trailPtr = list.dummyHead->next;

    while(searchPtr != nullptr){
        if(searchPtr->data == key){
            // Remove node from list
            trailPtr->next = searchPtr->next;
            searchPtr->next->prev = trailPtr;
            
            delete(searchPtr);
            *(list.size)--;
            return true;
        }

        trailPtr = searchPtr;
        searchPtr = searchPtr->next;
    }
    return false;
}

void freeList(List list){
    if(list.size){
        delete(list.size);
    }
    
    Node *traversePtr = list.dummyHead;
    Node *deletePtr = list.dummyHead;


    while(traversePtr != nullptr){
        traversePtr = traversePtr->next;
        delete(deletePtr);
        deletePtr = traversePtr;
    }
    list.dummyHead = nullptr;
}

void printList(List list){
    Node *printPtr = list.dummyHead->next;
    int count = 1;
    while(printPtr != nullptr){
        std::cout << "Node " << count << " data: " << std::setprecision(5) << printPtr->data << std::endl;
        count++;
        printPtr = printPtr->next;
    }
}