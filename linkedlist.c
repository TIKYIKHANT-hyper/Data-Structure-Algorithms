#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node listnode;
typedef listnode *listnodeptr;

void insert(listnodeptr *header, int inputdata);
int delete(listnodeptr *header, int value);
int isempty(listnodeptr header);
void printlist(listnodeptr header);

int main(){
    listnodeptr sptr = NULL;
    insert(&sptr,1);
    insert(&sptr,2);
    insert(&sptr,3);
    insert(&sptr,4);
    printlist(sptr);
    int key = isempty(sptr);
    printf("%c",key);
    return 0;
}

void insert(listnodeptr *header, int inputdata){
    listnodeptr newnode = malloc(sizeof(listnode));
    if(newnode != NULL){
        newnode->data = inputdata;
        newnode->next = NULL;
        listnodeptr previous = NULL;
        listnodeptr current = *header;
        while(current != NULL && inputdata > current->data){
            previous = current;
            current = current->next;
        }
        if(previous == NULL){
            newnode->next = *header;
            *header = newnode;
        }
        else{
            previous->next = newnode;
            newnode->next = current;
        }
    }
    else
    {
        printf("No Enough Memory for allocation\n");
    }
}

int delete(listnodeptr *header , int value){
    if(value == (*header)->data){
        listnodeptr temptr = *header;
        *header = (*header)->next;
        free(temptr);
    }
    else{
        listnodeptr previousptr = *header;
        listnodeptr currentptr = (*header)->next;
        while(currentptr != NULL && currentptr->data != value){
            previousptr = currentptr;
            currentptr = currentptr->next;
        }
        if(currentptr != NULL){
            listnodeptr temptr = currentptr;
            previousptr->next = currentptr->next;
            free(temptr);
            return value;
        }
    }
    return 1;
}

int isempty(listnodeptr header){
    return header == NULL;
}

void printlist(listnodeptr header){
    if(isempty(header)){
        printf("List is empty");
    }
    else{
        printf("The link is:\n");
        while(header != NULL){
            printf("%i --> ",header->data);
            header = header->next;
        }
        printf("That's all!\n");
    }
}