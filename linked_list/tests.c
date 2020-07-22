#include <stdio.h>
#include "linkedList.h"

int main(int argc, char *argv[]){
    LinkedList* listPtr = create_LinkedList();
    for(int i = 0; i < 20; i++){
        insert_LinkedList(listPtr,i);
    }
    printf("No nodes removed:\n\n");
    print_LinkedList(listPtr);
    
    printf("\n8 removed:\n\n");
    remove_LinkedList(listPtr,8);
    print_LinkedList(listPtr);

    printf("\n34 removed:\n\n");
    remove_LinkedList(listPtr,19);
    print_LinkedList(listPtr);

    printf("\n19 removed:\n\n");
    remove_LinkedList(listPtr,19);
    print_LinkedList(listPtr);

    printf("\n0 removed:\n\n");
    remove_LinkedList(listPtr,0);
    print_LinkedList(listPtr);

    printf("\nLooking for value 15\n");
    if(hasValue_LinkedList(listPtr,15)) printf("Value found!\n");
    else printf("Value not found!\n");

    printf("\nLooking for value 30\n");
    if(hasValue_LinkedList(listPtr,30)) printf("Value found!\n");
    else printf("Value not found!\n");


    free_LinkedList(listPtr);
    
}