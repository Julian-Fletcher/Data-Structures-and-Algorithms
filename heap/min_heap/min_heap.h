#include <iostream>

typedef struct heap{
    int *heap;
    int *cururent_size;
    int max_size;
}Heap;


Heap create_heap(int max_size);
bool insert(Heap heap, int data);
bool remove(Heap heap, int key);
int get_size(Heap heap);
bool isEmpty(Heap heap);
bool isFull(Heap heap);
void destroy_heap(Heap heap);


// Not front facing 
void heapify(int *heap, int index);

