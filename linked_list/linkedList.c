#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/**
 * Dynamically allocates a node. This function cannot and should not be called directly outside 
 * of this file.
 * 
 * @param value: The value to be stored in the node.
 * @return the allocated node.
 */
static Node* createNode_LinkedList(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = LIST_END;//Whenever a node is created, it is placed at the end of the list.
    return newNode;
}

static int isValidNode_LinkedList(Node* node){
    return !(node == LIST_INVALID_NODE);
}

static void removeNode_LinkedList(LinkedList* listPtr,Node* nodePtr,Node* previousNodePtr){
    if(previousNodePtr == LIST_START){//Node on head
        listPtr->head = nodePtr->next;
        free(nodePtr);
    }
    else{
        if (nodePtr->next == LIST_END){//Node on tail
            listPtr->tail = previousNodePtr;
        }
        previousNodePtr->next = nodePtr->next;
        free(nodePtr);
    }
    listPtr->length--;
}

LinkedList* create_LinkedList(){
    LinkedList* newLinkedList = (LinkedList*) malloc(sizeof(LinkedList));
    newLinkedList->head = LIST_EMPTY; //Define the list's first node as NULL (empty node).
    newLinkedList->tail = LIST_EMPTY; //Define the list's last node as NULL (empty node)'
    newLinkedList->length = 0;
    return newLinkedList;
}

void free_LinkedList (LinkedList* listPtr){
    Node* nodeIterator = listPtr->head;
    //foreach_LinkedList may not be used here since we would free the specified iterator.
    while(isValidNode_LinkedList(nodeIterator)){
        Node* previousNode = nodeIterator;
        nodeIterator = nodeIterator->next;
        free(previousNode);
    }
    free(listPtr);
}

int isEmpty_LinkedList(LinkedList* listPtr){
    return (listPtr->head == NULL) ? 1 : 0;
}

void insert_LinkedList (LinkedList* listPtr, int value){
    Node* newNode = createNode_LinkedList(value);
    if (isEmpty_LinkedList(listPtr)){
        listPtr->head = newNode;
        listPtr->tail = newNode;
    }
    else{
        Node* tail = listPtr->tail;
        tail->next = newNode;
        listPtr->tail = newNode;
    }
    listPtr->length++;
}

void remove_LinkedList (LinkedList* listPtr, int value){
    if (isEmpty_LinkedList(listPtr)) return;
    Node* nodeIterator = listPtr->head;
    Node* previousNode = LIST_START;
    foreach_LinkedList(nodeIterator,listPtr){
        if(nodeIterator->data == value){
            removeNode_LinkedList(listPtr,nodeIterator,previousNode);
            return;
        }
        previousNode = nodeIterator;
    }
}

int hasValue_LinkedList (LinkedList* listPtr, int searchedValue){
    if (isEmpty_LinkedList(listPtr)) return 0;
    Node* nodeIterator;
    foreach_LinkedList(nodeIterator,listPtr){
        if (nodeIterator->data == searchedValue) return 1;
    }
    return 0;              
}

void print_LinkedList (LinkedList* listPtr){
    if (isEmpty_LinkedList(listPtr)){
        printf("The list is empty\n");
        return;         
    }    
    Node* nodeIterator;
    foreach_LinkedList(nodeIterator,listPtr){
        printf("%d\n", nodeIterator->data);
    }   
}