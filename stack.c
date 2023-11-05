#include <stdio.h>
#include <stdlib.h>

struct stacknode{
    int data;
    struct stacknode *nextptr;
};

typedef struct stacknode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *baseptr,int inputdata);
int pop(StackNodePtr *baseptr);
void printStack(StackNodePtr baseptr);
int isEmpty(StackNodePtr baseptr);

int main(){
    StackNodePtr oneptr = NULL;
    push(&oneptr,1);
    push(&oneptr,2);
    push(&oneptr,3);
    printStack(oneptr);
    pop(&oneptr);
    printStack(oneptr);
}

void push(StackNodePtr *baseptr,int inputdata){
    StackNodePtr newptr = (malloc(sizeof(StackNode)));
    if(newptr != NULL){
        newptr->data = inputdata;
        newptr->nextptr = *baseptr;
        *baseptr = newptr;
    }
    else if(newptr == NULL){
        puts("Segmentation fault:!");
    }
}

int pop(StackNodePtr *baseptr){
    if(baseptr==NULL){
        puts("None Stack");
        return -1;
    }
    else{
    StackNodePtr temp = *baseptr;
    int popvalue = (*baseptr)->data;
    *baseptr = (*baseptr)->nextptr;
    free(temp);
    return popvalue;
    }
}

void printStack(StackNodePtr baseptr){
    StackNodePtr currentptr = baseptr;
    if(currentptr == NULL){
        puts("It is empty\n");
    }
    else{
        while(currentptr != NULL){
            printf("%d --> ",currentptr->data);
            currentptr = currentptr->nextptr;
        }
        puts("End");
    }
}

int isEmpty(StackNodePtr baseptr){
    return baseptr == NULL;
}