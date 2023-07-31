#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

int main(){
    struct node * root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);
    return 0;
}
