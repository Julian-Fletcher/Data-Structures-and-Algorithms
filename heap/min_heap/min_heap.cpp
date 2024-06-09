#include "min_heap.h"

MinHeap create_heap(int max_size){
    MinHeap heap;
    heap.array = new int[max_size];      // Create heap array
    heap.max_size = max_size;
    heap.current_size = new int;      // Pointer so it can be updated without user passing a pointer
    *(heap.current_size) = 0;
    return heap;
}


bool insert(MinHeap heap, int data){
    if(isFull(heap)){
        return false;
    }

    *(heap.current_size) += 1;             // Increment size of heap

    int index = *(heap.current_size) - 1;  // Get insertion index

    heap.array[index] = data;               // Insert into the array

    min_heapify_up(heap.array, index);             // Heapify up from that index
    
    return true;
}

int extract(MinHeap heap){
    int removed = heap.array[0];
    int last_index = get_size(heap) - 1;
    heap.array[0] = heap.array[last_index];         // Swap with the last element of the array
    *(heap.current_size) -= 1;                     // Update heap size
    last_index = get_size(heap) - 1;                // Update last index in the array
    min_heapify_down(heap.array, 0, last_index);    // Heapify from the root of the tree
    return removed;
}

int get_size(MinHeap heap){
    return *(heap.current_size);
}

bool isEmpty(MinHeap heap){
    if(*(heap.current_size) == 0){
        return true;
    }
    return false;
}

bool isFull(MinHeap heap){
    if(*(heap.current_size) == heap.max_size){
        return true;
    }
    return false;
}

void destroy_heap(MinHeap heap){
    delete heap.array;
    delete heap.current_size;
}

// Not front facing 
void min_heapify_up(int *heap, int index){
    int parent = (index - 1) / 2;       // Find parent index
    
    // Ensure the index remains in the array bounds
    if(index == 0){
        return;
    }

    // Check if the parent-child maintain proper relationship
    if(heap[index] < heap[parent]){
        std::swap(heap[index], heap[parent]);               // Swap array elements
        min_heapify_up(heap, parent);                       // Recursive call to heapify up the tree
    }
}

void min_heapify_down(int *heap, int parent, int size){
    // If a left child doesn't exist, the node has no children 
    // And there is no need to heapify
    // "Base case"
    if((parent * 2) + 1 > size){
        return;
    }

    // Children variables 
    int left_child = (parent * 2) + 1;
    int right_child = (parent * 2) + 2;
    int smallest_child = left_child;
    
    // Check if right child is the smallest child
    if(right_child < size && heap[right_child] < heap[left_child]){
        smallest_child = right_child;
    }

    // Check if valid heap structure
    if(heap[parent] > heap[smallest_child]){
        std::swap(heap[parent], heap[smallest_child]);          // Swap the nodes
        min_heapify_down(heap, smallest_child, size);           // Recursive call down the tree
    }
    
}

void print_heap(MinHeap heap){

    std::cout << "*** Printing MinHeap ***" << std::endl;

    for(int i = 0; i < get_size(heap); i++){
        std::cout << heap.array[i] << ", ";
    }
    std::cout << std::endl;
}