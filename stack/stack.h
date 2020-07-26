//Author: https://github.com/pedrohdjs
//This is a simple integer storing linked stack.

#ifndef STACK_H
#define STACK_H

#define STACK_EMPTY NULL
#define STACK_EMPTY_VALUE 0
#define STACK_END NULL
#define STACK_INVALID_NODE NULL

/**
 * Processes each node in a stack.
 * 
 * @param nodePtr: A node pointer used as a iterator
 * @param stackPtr: A pointer to a stack
 */
#define foreach_Stack(nodePtr,stackPtr)\
    for(nodePtr = stackPtr->head; nodePtr != NULL; nodePtr = nodePtr->next)

//A node, containing both it's own data and a pointer to the next node in the list-based data structure.
typedef struct node {
    int data;
    struct node *next;
} Node;

//A pointer to a node, allowing dynamic allocation of linked lists.
typedef struct stack{
    Node* head;
} Stack;

/**
 * Create a dynamically allocated stack. 
 * Complexity in this implementation: O(1).
 * 
 * @return a pointer to a newly allocated stack.
 */
Stack* create_Stack();

/**
 * Frees memory allocated for a dynamically allocated stack. This function should always be called
 * after finishing the stack's use in order to prevent memory leaks. 
 * Complexity in this implementation: O(n).
 * 
 * @return void
 */
void free_Stack (Stack* stackPtr);

/**
 * Determines if a given stack is empty. 
 * Complexity in this implementation: O(1).
 * 
 * @param stackPtr: A pointer to a stack
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty_Stack(Stack* stackPtr);


/**
 * Inserts a node with the specified value into the head of the specified stack.
 * Complexity in this implementation: O(1).
 * 
 * @param stackPtr: A pointer to a stack
 * @param value: The value to be pushed into the stack
 * @return void
 */
void push_Stack (Stack* stackPtr, int value);

/**
 * Pops the head node of the stack, returning it's value.
 * Complexity in this implementation: O(1).
 * 
 * @param stackPtr: A pointer to a linked list
 * @param value: The value to be removed of the linked list.
 * @return the value of the previous head node on the stack, or 0 if the stack is empty.
 */
int pop_Stack (Stack* stackPtr);

/**
 * Prints all elements of the given stack. 
 * Complexity in this implementation: O(n).
 * 
 * @param listPtr: A pointer to a linked list
 * @return void
 */
void print_Stack (Stack* stackPtr);

#endif //STACK_H