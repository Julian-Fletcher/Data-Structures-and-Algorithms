#include "queue.h"
#include <stdio.h>

int main(){
    Queue queue = initQueue(15);

    bool full = isFull(queue);
    bool empty = isEmpty(queue);

    std::cout << "isFull returned " << full << " and isEmpty returned " << isEmpty << std::endl;


    int data_array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    for(int item : data_array){
        enqueue(queue, item);
    }
    

    std::cout << "First item in queue " << peek(queue) << std::endl;

    int v1 = dequeue(queue);
    int v2 = dequeue(queue);

    std::cout << "Dequeued " << v1 << " and " << v2 << std::endl;

    full = isFull(queue);
    empty = isEmpty(queue);

    std::cout << "isFull returned " << full << " and isEmpty returned " << empty << std::endl;

    bool del = deleteQueue(queue);
    std::cout << "Delete returned " << std::boolalpha << del << std::endl;
}