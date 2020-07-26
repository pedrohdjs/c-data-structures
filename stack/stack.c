#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/**
 * Dynamically allocates a node. This function cannot and should not be called directly outside 
 * of this file.
 * 
 * @param value: The value to be stored in the node.
 * @param next: The next node on the stack (current head)
 * @return the allocated node.
 */
static Node* createNode_Stack(int value, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = next;
    return newNode;
}

static int isValidNode_Stack(Node* node){
    return !(node == STACK_INVALID_NODE);
}

//Moves the stacks's head to it's head's following node.
static void shiftHead_Stack(Stack* stackPtr){
    Node* head = stackPtr->head;
    stackPtr->head = head->next;
    free(head);
}

Stack* create_Stack(){
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    newStack->head = STACK_EMPTY; //Define the list's first node as NULL (empty node).
    return newStack;
}

void free_Stack (Stack* stackPtr){
    Node* nodeIterator = stackPtr->head;
    //foreach_Stack may not be used here since we would free the specified iterator.
    while(isValidNode_Stack(nodeIterator)){
        Node* previousNode = nodeIterator;
        nodeIterator = nodeIterator->next;
        free(previousNode);
    }
    free(stackPtr);
}

int isEmpty_Stack(Stack* stackPtr){
    return (stackPtr->head == NULL) ? 1 : 0;
}

void push_Stack (Stack* stackPtr, int value){
    Node* newNode = createNode_Stack(value,stackPtr->head);
    stackPtr->head = newNode;
}

int pop_Stack (Stack* stackPtr){
    if (isEmpty_Stack(stackPtr)) return STACK_EMPTY_VALUE;
    Node* head = stackPtr->head;
    int headValue = head->data;
    shiftHead_Stack(stackPtr);
    return headValue;
}


void print_Stack (Stack* stackPtr){
    if (isEmpty_Stack(stackPtr)){
        printf("The stack is empty\n");
        return;         
    }    
    Node* nodeIterator;
    foreach_Stack(nodeIterator,stackPtr){
        printf("%d\n", nodeIterator->data);
    }   
}