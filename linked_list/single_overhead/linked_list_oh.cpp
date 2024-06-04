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

void insertAtHead(List list, void *data);
bool deleteItem(List list, void *key, int (*comp_func)(void *a, void *b));
bool freeList(List list);
void printList(List list, std::string(*print_func)(void *data));