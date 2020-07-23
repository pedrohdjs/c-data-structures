#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]){
    Stack* stackPtr = create_Stack();
    for(int i = 1; i <= 5; i++){
        push_Stack(stackPtr,i);
    }
    print_Stack(stackPtr);
    for(int i = 0; i < 6; i++){
        printf("Popped value: %d\n", pop_Stack(stackPtr));
        print_Stack(stackPtr);
    }
    free_Stack(stackPtr);
    
}