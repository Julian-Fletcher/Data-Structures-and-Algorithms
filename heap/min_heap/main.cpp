#include "min_heap.h"

int main(){
    Heap heap = create_heap(10);

    std::cout << "Full? " << std::boolalpha << isFull(heap) << " Empty? " << std::boolalpha << isEmpty(heap) << " size? " << get_size(heap) << std::endl;

    destroy_heap(heap);

}