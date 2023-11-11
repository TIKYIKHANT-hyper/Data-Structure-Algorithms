#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef Node * nptr;

int isEmpty(nptr headptr);
void enqueue(nptr *headptr, nptr *tailptr,int value);
int dequeue(nptr *headptr, nptr *tailptr);
void printQueue(nptr headptr);

int main(){
    nptr testhead = NULL;
    nptr testtail = NULL;
    enqueue(&testhead,&testtail,1);
    enqueue(&testhead,&testtail,2);
    enqueue(&testhead,&testtail,3);
    enqueue(&testhead,&testtail,4);
    printQueue(testhead);
    dequeue(&testhead,&testtail);
    puts("after one node is dequeued!\n");
    printQueue(testhead);
    return 0;
}
int isEmpty(nptr headptr){
    return headptr == NULL;
}

void enqueue(nptr *headptr, nptr *tailptr,int value){
    nptr newptr = malloc(sizeof(Node));
    if(newptr != NULL){
        newptr->data = value;
        newptr->next = NULL;
        if(isEmpty(*headptr)){
            *headptr = newptr;
        }
        else{
            (*tailptr)->next = newptr;
        }
        *tailptr = newptr;
    }
    else{
        printf("Data %i not inserted, memory not available\n",value);
    }
}

int dequeue(nptr *headptr, nptr *tailptr){
    int value = (*headptr)->data;
    nptr temp = *headptr;
    *headptr = (*headptr)->next;
    if(*headptr==NULL){
        *tailptr = NULL;
    }
    free(temp);
    return value;
}

void printQueue(nptr headptr){
    if(headptr == NULL){
        puts("Queue is empty.");
    }
    else{
        puts("The queue is:");
        while(headptr != NULL){
            printf("%i --> ",headptr->data);
            headptr = headptr->next;
        }
        puts("NULL\n");
    }
}