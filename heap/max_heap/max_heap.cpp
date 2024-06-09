#include "max_heap.h"


MaxHeap create_heap(int max_size){
    MaxHeap heap;
    heap.array = new int[max_size];     // Create heap array
    heap.max_size = max_size;
    heap.current_size = new int;        // Dynamic variable to be modified later
    *(heap.current_size) = 0;
    return heap;
}


bool insert(MaxHeap heap, int data){
    if(isFull(heap)){
        return false;
    }
    *(heap.current_size) += 1;          // Increment size of heap
    int index = *(heap.current_size) - 1;
    heap.array[index] = data;
    max_heapify_up(heap.array, index);
    return true;
}


int extract(MaxHeap heap){
    int removed = heap.array[0];
    int last_index = get_size(heap) - 1;
    heap.array[0] = heap.array[last_index];         // Swap with the last element of the array
    *(heap.current_size) -= 1;                     // Update heap size
    last_index = get_size(heap) - 1;                // Update last index in the array
    max_heapify_down(heap.array, 0, last_index);    // Heapify from the root of the tree
    return removed;
}

int get_size(MaxHeap heap){
    return *(heap.current_size);
}

bool isEmpty(MaxHeap heap){
    return (*(heap.current_size) == 0);
}


bool isFull(MaxHeap heap){
    return (*(heap.current_size) == heap.max_size);
}


void destroy_heap(MaxHeap heap){
    delete heap.array;
    delete heap.current_size;
}

void print_heap(MaxHeap heap){
    std::cout << "*** Printing MaxHeap ***" << std::endl;

    for(int i = 0; i < get_size(heap); i++){
        std::cout << heap.array[i] << ", ";
    }
    std::cout << std::endl;
}


// Not front facing 
void max_heapify_up(int *heap, int index){
    // "Base case"
    if(index == 0){
        return;
    }

    int parent = (index - 1) / 2;       // Find parent index

     // Check if the parent-child maintain proper relationship
    if(heap[index] > heap[parent]){
        std::swap(heap[index], heap[parent]);           // Swap array elements
        max_heapify_up(heap, parent);                      // Recursive call to heapify up the tree
    }
}

void max_heapify_down(int *heap, int parent, int size){
    // If a left child doesn't exist, the node has no children 
    // And there is no need to heapify
    // "Base case"
    if((parent * 2) + 1 > size){
        return;
    }

    // Children variables 
    int left_child = (parent * 2) + 1;
    int right_child = (parent * 2) + 2;
    int largest_child = left_child;
    
    // Check if right child is the largest child
    if(right_child < size && heap[right_child] > heap[left_child]){
        largest_child = right_child;
    }

    // Check if valid heap structure
    if(heap[parent] < heap[largest_child]){
        std::swap(heap[parent], heap[largest_child]);          // Swap the nodes
        max_heapify_down(heap, largest_child, size);           // Recursive call down the tree
    }
    
}