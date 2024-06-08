#include "priority_queue.h"


int main(){
    Queue queue = initQueue(15);

    bool full = isFull(queue);
    bool empty = isEmpty(queue);

    std::cout << "isFull returned " << std::boolalpha << full << " and isEmpty returned " << std::boolalpha << isEmpty << std::endl;


    int data_array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int priority[] = {2, 5, 0, 8, 6, 10, 35, 2, 8, 9, 14, 20, 21, 4, 3};

    int i = 0;
    for(int item: data_array){
        enqueue(queue, item, priority[i]);
        i++;
    }
    

    std::cout << "First item in queue " << peek(queue) << std::endl;

    int v1 = dequeue(queue);
    int v2 = dequeue(queue);

    std::cout << "Dequeued " << v1 << " and " << v2 << std::endl;

    full = isFull(queue);
    empty = isEmpty(queue);

    std::cout << "isFull returned " << std::boolalpha << full << " and isEmpty returned " << std::boolalpha << empty << std::endl;

    bool del = deleteQueue(queue);
    std::cout << "Delete returned " << std::boolalpha << del << std::endl;
}