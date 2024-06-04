#include "linked_list.hpp"
#include <string>

int compare_int(void *a, void *b){
    int A = *((int *)a);
    int B = *((int *)b);
    int C = A - B;

    // Return -1 if B > A
    if(C < 0){
        return -1;
    }

    // Return 1 if A > B
    if(C > 0){
        return 1;
    }

    // Return 0 if equal
    return C;
}

// Print the integer!!!
std::string print_int(void * data){
    int d = *((int *)data);
    return std::to_string(d);
}


int main(){
    int data[] = {1,2,3,4,5,6,7,8,9,10};

    // Create list with beginning
    Node *list = createList((void*)data);

    for(int i = 1; i < 10;i++){
        list = insertAtHead(list, (void*)(data + i));
    }
    // Create function pointer for compare_int
    int (*comparePtr)(void *, void *);
    comparePtr = compare_int;

    // Create function pointer for print_int
    std::string (*print)(void *);
    print = print_int;

    printList(list, print);

    void * deleted_item;
    deleted_item = deleteItem(list, (void *)(data + 4), comparePtr);
    std::cout << "Deleted Item: " << *((int *)deleted_item) << std::endl;

    printList(list, print);

    list = freeList(list);

}