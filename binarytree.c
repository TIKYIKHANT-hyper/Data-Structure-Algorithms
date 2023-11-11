#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode{
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
int main(){
    TreeNodePtr rootPtr = NULL;
    puts("numbers generated:");
    for(int i = 1; i<=10; ++i){
        int item = rand() % 15;
        printf("%3i",item);
        insertNode(&rootPtr, item);
    }
    puts("inOrder traversal:");
    inOrder(rootPtr);
    return 0;
}

void insertNode(TreeNodePtr *treePtr, int value){
    if(*treePtr == NULL){
        *treePtr = malloc(sizeof(TreeNode));
        if(*treePtr != NULL){
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else{
            printf("%i not inserted. No memory available.\n",value);
        }
    }
    else{
        if(value < (*treePtr)->data){
            insertNode((&(*treePtr)->leftPtr),value);
        }
        else if(value > (*treePtr)->data){
            insertNode((&(*treePtr)->rightPtr),value);
        }
        else{
            printf("%s","dup");
        }
    }
}

void inOrder(TreeNodePtr treePtr){
    if(treePtr!=NULL){
        inOrder(treePtr->leftPtr);
        printf(" %3i ",treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}