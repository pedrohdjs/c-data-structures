#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Dynamically allocates a node. This function cannot and should not be called directly outside 
 * of this file.
 * 
 * @param value: The value to be stored in the node.
 * @return the allocated node.
 */
static Node* createNode_Queue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = QUEUE_END;
    return newNode;
}

/*Assigns a given node as both the head and the tail of the queue. Used on enqueue when the
queue is empty.*/
static void assignStartingNode_Queue(Queue* queuePtr,Node* nodePtr) {
    queuePtr->head = nodePtr;
    queuePtr->tail = nodePtr;
}

//Assigns the Queue's tail node properly, without breaking the linking in the list-like structure.
static void assignTailNode_Queue(Queue* queuePtr,Node* nodePtr) {
        Node* tail = queuePtr->tail;
        tail->next = nodePtr;
        queuePtr->tail = nodePtr;

}

//Moves the queue's head to it's head's following node.
static void shiftHead_Queue(Queue* queuePtr){
    Node* head = queuePtr->head;
    queuePtr->head = head->next;
    free(head);
}


static int isValidNode_Queue(Node* nodePtr){
    return !(nodePtr == QUEUE_INVALID_NODE);
}

Queue* create_Queue(){
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->head = QUEUE_EMPTY; 
    newQueue->tail = QUEUE_EMPTY; 
    return newQueue;
}

void free_Queue (Queue* queuePtr){
    Node* nodeIterator = queuePtr->head;
    //foreach_Queue may not be used here since we would free the specified iterator.
    while(isValidNode_Queue(nodeIterator)){
        Node* previousNode = nodeIterator;
        nodeIterator = nodeIterator->next;
        free(previousNode);
    }
    free(queuePtr);
}

int isEmpty_Queue(Queue* queuePtr){
    return (queuePtr->head == QUEUE_EMPTY) ? 1 : 0;
}

void enqueue_Queue (Queue* queuePtr, int value){
    Node* newNode = createNode_Queue(value);
    if (isEmpty_Queue(queuePtr)){
        assignStartingNode_Queue(queuePtr, newNode);
    }
    else{
        assignTailNode_Queue(queuePtr, newNode);
    }
}

int dequeue_Queue (Queue* queuePtr){
    if (isEmpty_Queue(queuePtr)) return QUEUE_EMPTY_VALUE;
    Node* head = queuePtr->head;
    int headValue = head->data;
    shiftHead_Queue(queuePtr);
    return headValue;
}

void print_Queue (Queue* queuePtr){
    if (isEmpty_Queue(queuePtr)){
        printf("The queue is empty\n");
        return;         
    }    
    Node* nodeIterator;
    foreach_Queue(nodeIterator,queuePtr){
        printf("%d\n", nodeIterator->data);
    }   
}