#include "linked_list_oh.h"

int main(){
    float data[] = {2.2,3.3,4.7,8.9,5.5,6.0,9.12,7.6, 5.5, 8.8};

    List list = createList();
    std::cout << "Starting list size: " << getListSize(list) << std::endl;

    for(float i : data){
        insertAtHead(list, i);
    }

    std::cout << "List size after insertion: " << getListSize(list) << std::endl;
    printList(list);

    bool del = deleteItem(list, 3.3);

    std::cout << "List size after deletion: " << getListSize(list) << std::endl;
    printList(list);


    freeList(list);
}