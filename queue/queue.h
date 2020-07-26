/*Author: https://github.com/pedrohdjs under MIT license
This is a simple integer storing queue, with pointers to it's head and it's tail.
The queue's tail stores newly inserted values, while it's head stores the oldest value.
This is important in order to preserve the FIFO (First in - First out) order.*/

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_END NULL
#define QUEUE_START NULL
#define QUEUE_EMPTY NULL
#define QUEUE_INVALID_NODE NULL
#define QUEUE_EMPTY_VALUE 0

/**
 * Processes each node in a queue.
 * 
 * @param nodePtr: A node pointer used as a iterator
 * @param queuePtr: A pointer to a queue
 */
#define foreach_Queue(nodePtr,queuePtr)\
    for(nodePtr = queuePtr->head; nodePtr != QUEUE_INVALID_NODE; nodePtr = nodePtr->next)

//A node, containing both it's own data and a pointer to the next node in the list-based data structure.
typedef struct node {
    int data;
    struct node *next;
} Node;

//A pointer to a node, allowing dynamic allocation of queues.
typedef struct queue{
    Node* head;
    Node* tail;
} Queue;

/**
 * Create a dynamically allocated queue. 
 * Complexity in this implementation: O(1).
 * 
 * @return a pointer to a newly allocated queue.
 */
Queue* create_Queue();

/**
 * Frees memory allocated for a dynamically allocated queue. This function should always be called
 * after finishing the queue's use in order to prevent memory leaks. 
 * Complexity in this implementation: O(n).
 * 
 * @return void
 */
void free_Queue (Queue* queuePtr);

/**
 * Determines if a given queue is empty. 
 * Complexity in this implementation: O(1).
 * 
 * @param queuePtr: A pointer to a queue
 * @return 1 if the queue is empty, 0 if it is not empty.
 */
int isEmpty_Queue(Queue* queuePtr);


/**
 * Inserts a node in the queue's tail. 
 * 
 * @param queuePtr: A pointer to a queue
 * @param value: The value to be inserted into the queue.
 * @return void
 */
void enqueue_Queue (Queue* queuePtr, int value);

/**
 * Removes the node at the queue's head and returns it's value.
 * 
 * @param queuePtr: A pointer to a queue
 * @return the value stored in the head of the queue.
 */
int dequeue_Queue (Queue* queuePtr);

/**
 * Prints all elements of the given queue. 
 * Complexity in this implementation: O(n).
 * 
 * @param queuePtr: A pointer to a queue
 * @return void
 */
void print_Queue (Queue* queuePtr);

#endif //QUEUE_H