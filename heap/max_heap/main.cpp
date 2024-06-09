#include "max_heap.h"

int main(){
    MaxHeap heap = create_heap(10);

    int data[] = {15, 10, 8, 12, 20, 5, 25, 30, 18, 9};

    for(int i : data){
        insert(heap, i);
    }

    print_heap(heap);
    std::cout << "Full? " << std::boolalpha << isFull(heap) << " Empty? " << std::boolalpha << isEmpty(heap) << " size? " << get_size(heap) << std::endl;

    int deleted = extract(heap);
    std::cout << "Extracted element: " << deleted << std::endl;

    print_heap(heap);

    destroy_heap(heap);

}