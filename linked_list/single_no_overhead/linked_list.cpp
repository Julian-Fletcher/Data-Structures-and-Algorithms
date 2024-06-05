#include "linked_list.hpp"


// Creates and returns the beginning of a list to the user
Node * createList(void *data){
    Node *list = new(Node);
    list->data = data;
    list->next = nullptr;
    return list;
}


int getListSize(Node *head){
    if(head == nullptr){
        return 0;
    }
    int count = 1;
    Node *p = head;
    while(p->next != nullptr){
        p=p->next;
        count++;
    }
    return count;
}


Node * insertAtHead(Node *head, void *data){
    // If the provided head node hasn't been initialized then do nothing
    if(head == nullptr){
        return nullptr;
    }
    Node *node = new(Node);
    node->data = data;
    node->next = head;
    return node;
}

// Deletes an item from the list
void * deleteItem(Node *head, void *key, int (*comp_func)(void *a, void *b)){
    // Pointers to increment through list
    Node *p = head;     // Holds current position in the list
    Node *q = head;     // Holds location of previous node

    // Pointer to hold the user data to return (if found)
    void *usrData = nullptr;

    // Loop through the list in O(n) and find node with data
    // Until the last node in the list is reached
    while(p->next != nullptr){

        // Exit the loop and store the data if the item is found
        if(p->data == key){
            usrData = p->data;      // Store the data in the node
            q->next = p->next;      // Remove the current (p) node from the list
            delete(p);              // Free the current node
            break;
        }
        // Move each pointer forward by 1 node
        q = p;
        p = p->next;
    }

    // Return a nullptr or the requested data
    return usrData;
}

Node * freeList(Node *head){
    Node *p = head;         // Will move forward in the list
    Node *q = head;         // Will handle the deletion of nodes

    while(p->next !=nullptr){
        p = p->next;
        delete(q);
        q = p;
    }
    delete(p);
    return nullptr;
}

void printList(Node *head, std::string(*print_func)(void *data)){
    if(head == nullptr){
        std::cout << "Error, no list" << std::endl;
        return;
    }
    int count = 1;
    Node *p = head;
    while(p->next != nullptr){
        std::cout << "Node " << count << " with data item: '" << (print_func)(p->data) << "'" << std::endl;
        count++;
        p = p->next;
    }
    std::cout << "Node " << ++count << " with data item: '" << (print_func)(p->data) << "'" << std::endl;
}