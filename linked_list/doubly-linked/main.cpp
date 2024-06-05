#include "doubly_linked.h"

int main(){
    double data[] = {3.333, 23.452, 2234.2342, 9945.34, 0.00003, 3.442, 5.66666789, .9232, 9482.1341, 0.001};

    List list = createList();
    
    for(int item : data){
        insertAtHead(list, item);
    }

    std::cout << "Items in list: " << getListSize << std::endl;

    printList(list);

    deleteItem(list, data[5]);
    
    std::cout << "Items in list: " << getListSize << std::endl;

    printList(list);

    freeList(list);
}