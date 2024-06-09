#include "min_heap.h"

int main(){
    MinHeap heap = create_heap(20);

    int data[] = {10, 20, 5, 6, 1, 8, 9, 3, 4, 2, 7};

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