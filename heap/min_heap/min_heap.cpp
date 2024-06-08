#include "min_heap.h"

Heap create_heap(int max_size){
    Heap heap;
    heap.heap = new int(max_size);      // Create heap array
    heap.max_size = max_size;
    heap.cururent_size = new int;      // Pointer so it can be updated without user passing a pointer
    *(heap.cururent_size) = 0;
    return heap;
}


bool insert(Heap heap, int data){
    if(isFull){
        return false;
    }
    *(heap.cururent_size) += 1;
    
    
}

bool remove(Heap heap, int key){
    return true;
}

int get_size(Heap heap){
    return *(heap.cururent_size);
}

bool isEmpty(Heap heap){
    if(*(heap.cururent_size) == 0){
        return true;
    }
    return false;
}

bool isFull(Heap heap){
    if(*(heap.cururent_size) == heap.max_size){
        return true;
    }
    return false;
}

void destroy_heap(Heap heap){
    delete heap.heap;
    delete heap.cururent_size;
}

// Not front facing 
void heapify(int *heap, int index);