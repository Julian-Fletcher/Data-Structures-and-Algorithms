#include "priority_queue.h"


Queue initQueue(int max_size){
    Queue queue;
    queue.head = new(Node);
    queue.tail = new(Node);

    // Dummy nodes point to start of list set null
    queue.head->next = nullptr;
    queue.tail->next = nullptr;

    queue.max_size = max_size;
    queue.current_size = new int;   // Dynamic size field so it can be updated 
    return queue;
}


int enqueue(Queue queue, int data, int priority){
    // Create node and fill with data
    Node *newNode = new(Node);
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = nullptr;

    // If the queue is empty, the new node will be pointed to by tail and head
    if(queue.head->next == nullptr){
        queue.head->next = newNode;
        queue.tail->next = newNode;
        *(queue.current_size) = 1;
        return 0;
    }

    *(queue.current_size) += 1;
    
    Node *locator = queue.head->next;       // Searches for correct position in list
    
    while(locator->next != nullptr){
        if(locator->priority >= priority){
            // Insert after the current node
            newNode->next = locator->next;
            locator->next = newNode;
            return 0;
        }
        locator = locator->next;
    }

    // Insert at the tail of the queue -- lowest priority member
    queue.tail->next->next = newNode;
    queue.tail->next = newNode;
    return 0;

}

int dequeue(Queue queue){
    // Move head pointer to next node
    Node *p = queue.head->next;
    queue.head->next = queue.head->next->next;
    
    int data = p->data;        // Save person data
    delete p;                       // Delete the node
    return data;                    // Return the data
}


int peek(Queue queue){
    return queue.head->next->data;
}

bool isEmpty(Queue queue){
    if(*(queue.current_size) != 0) return false;
    
    return true;
}


bool isFull(Queue queue){
    if(queue.max_size == *(queue.current_size)) return true;
    
    return false;
}

bool deleteQueue(Queue queue){
    Node *traversePtr = queue.head->next;
    Node *deletePtr = queue.head->next;

    while(traversePtr != nullptr){
        traversePtr = traversePtr->next;
        delete deletePtr;
        deletePtr = traversePtr;
    }
    delete queue.head;
    delete queue.tail;
    delete queue.current_size;
    return true;
}