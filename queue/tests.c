#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[]){
    Queue* queuePtr = create_Queue();
    for(int i = 0; i < 10; i++){
        enqueue_Queue(queuePtr,i);
    }
    printf("No dequeues:\n\n");
    print_Queue(queuePtr);
    
    printf("\n1st dequeue:\n\n");
    dequeue_Queue(queuePtr);
    print_Queue(queuePtr);

    printf("\nAnother enqueue:\n\n");
    enqueue_Queue(queuePtr,10);
    print_Queue(queuePtr);

    printf("\n2nd dequeue:\n\n");
    dequeue_Queue(queuePtr);
    print_Queue(queuePtr);

    free_Queue(queuePtr); 
}