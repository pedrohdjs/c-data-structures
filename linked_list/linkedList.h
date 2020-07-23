//Author: https://github.com/pedrohdjs
//This is a simple integer storing linked list, with pointers to it's head and it's tail.

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define LIST_END NULL
#define LIST_START NULL
#define LIST_EMPTY NULL
#define LIST_INVALID_NODE NULL

/**
 * Processes each node in a linked list.
 * 
 * @param nodePtr: A node pointer used as a iterator
 * @param listPtr: A pointer to a linked list
 */
#define foreach_LinkedList(nodePtr,listPtr)\
    for(nodePtr = listPtr->head; nodePtr != NULL; nodePtr = nodePtr->next)

//A node, containing both it's own data and a pointer to the next node in the list.
typedef struct node {
    int data;
    struct node *next;
} Node;

//A pointer to a node, allowing dynamic allocation of linked lists.
typedef struct linkedList{
    Node* head;
    Node* tail;
    int length;
} LinkedList;

/**
 * Create a dynamically allocated linked list. 
 * Complexity in this implementation: O(1).
 * 
 * @return a pointer to a newly allocated linked list.
 */
LinkedList* create_LinkedList();

/**
 * Frees memory allocated for a dynamically allocated linked list. This function should always be called
 * after finishing the list's use in order to prevent memory leaks. 
 * Complexity in this implementation: O(n).
 * 
 * @return void
 */
void free_LinkedList (LinkedList* listPtr);

/**
 * Determines if a given linked list is empty. 
 * Complexity in this implementation: O(1).
 * 
 * @param listPtr: A pointer to a linked list
 * @return 0 if the list is empty, 1 if it is not empty.
 */
int isEmpty_LinkedList(LinkedList* listPtr);


/**
 * Inserts a node with the specified value into the specified linked list. 
 * Complexity in this implementation (Thanks 
 * to the use of a tail node pointer): O(1).
 * 
 * @param listPtr: A pointer to a linked list
 * @param value: The value to be inserted into the linked list.
 * @return void
 */
void insert_LinkedList (LinkedList* listPtr, int value);

/**
 * Removes the first node containing the specified value from the linked list. 
 * Complexity in this implementation: O(n).
 * 
 * @param listPtr: A pointer to a linked list
 * @param value: The value to be removed of the linked list.
 * @return void
 */
void remove_LinkedList (LinkedList* listPtr, int value);

/**
 * Performs a linear search for the specified value in the specified linked list. 
 * Complexity in this implementation: O(n).
 * 
 * @param listPtr: A pointer to a linked list
 * @param searchedValue: The searched value on the list.
 * @return 1 if the element is found, 0 otherwise.
 */
int hasValue_LinkedList (LinkedList* listPtr, int searchedValue);

/**
 * Prints all elements of the given linked list. 
 * Complexity in this implementation: O(n).
 * 
 * @param listPtr: A pointer to a linked list
 * @return void
 */
void print_LinkedList (LinkedList* listPtr);

#endif //LINKED_LIST_H