#include <iostream>

typedef struct node{
    int data;
    node *next;
}Node;

typedef struct queue{
    Node *head;
    Node *tail;
    int max_size;
    int *current_size;
}Queue;


Queue initQueue(int max_size);
int enqueue(Queue queue, int data);
int dequeue(Queue queue);
int peek(Queue queue);
bool isEmpty(Queue queue);
bool isFull(Queue queue);
bool deleteQueue(Queue queue);