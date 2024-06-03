#include "linked_list.h"


// Creates and returns the beginning of a list to the user
Node * createList(void *data){
    Node *list = new(Node);
    list->data = data;
    list->next = nullptr;
    return list;
}


Node * getListSize(Node *head){

}


Node * insertAtHead(Node *head, void *data){
    Node *node = new(Node);
    node->data = data;
    node->next = head;
    return node;
}

void * deleteItem(Node *head, void *key){

}

Node * freeList(){

}






int main(){

}