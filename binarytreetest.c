#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node * leftleaf;
    struct node * rightleaf;
};

typedef struct node Node;
typedef Node* Nptr;

void insertNode(Nptr * root, int value){
    if(*root == NULL){
        *root = malloc(sizeof(Node));
        if(*root == NULL){
            printf("%d not inserted. No memory available.\n", value);
        }
        (*root)->leftleaf = NULL;
        (*root)->rightleaf = NULL;
    }
}
int main(){
    Nptr base = NULL;
    insertNode(&base, 1);
    insertNode(&base->leftleaf,2);
    insertNode(&base->rightleaf,3);
    insertNode(&base->leftleaf->leftleaf,4);
    insertNode(&base->leftleaf->rightleaf,5);
    insertNode(&base->rightleaf->leftleaf,6);
    insertNode(&base->rightleaf->rightleaf,7);
}
