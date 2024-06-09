#include <iostream>

typedef struct heap{
    int *array;
    int *current_size;
    int max_size;
}MinHeap;


MinHeap create_heap(int max_size);
bool insert(MinHeap heap, int data);
int extract(MinHeap heap);
int get_size(MinHeap heap);
bool isEmpty(MinHeap heap);
bool isFull(MinHeap heap);
void destroy_heap(MinHeap heap);
void print_heap(MinHeap heap);


// Not front facing 
void min_heapify_up(int *heap, int index);
void min_heapify_down(int *heap, int parent, int size);