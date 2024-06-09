#include <iostream>

typedef struct max_heap{
    int *array;
    int *current_size;
    int max_size;
}MaxHeap;

MaxHeap create_heap(int max_size);
bool insert(MaxHeap heap, int data);
int extract(MaxHeap heap);
int get_size(MaxHeap heap);
bool isEmpty(MaxHeap heap);
bool isFull(MaxHeap heap);
void destroy_heap(MaxHeap heap);
void print_heap(MaxHeap heap);


// Not front facing 
void max_heapify_up(int *heap, int index);
void max_heapify_down(int *heap, int parent, int size);
