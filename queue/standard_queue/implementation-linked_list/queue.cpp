#include "queue.h"

Queue initQueue(int max_size){
    Queue queue;
    queue.head = new(Node);
    queue.tail = new(Node);

    queue.head->next = nullptr;
    queue.tail->next = nullptr;
    queue.max_size = max_size;
    queue.current_size = new int;
    return queue;
}


int enqueue(Queue queue, int data){
    Node *newNode = new(Node);
    newNode->data = data;
    newNode->next = nullptr;

    std::cout << *(queue.current_size) << std::endl;

    // If the queue is empty, the new node will be pointed to by tail and head
    if(queue.head->next == nullptr){
        queue.head->next = newNode;
        queue.tail->next = newNode;
        *(queue.current_size) = 1;
        return 0;
    }

    *(queue.current_size) += 1;
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
