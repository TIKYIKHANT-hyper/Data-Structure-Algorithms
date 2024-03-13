//
// Created by TIKYI on 3/14/2024.
//
#include <stdio.h>
void swap(int *num1ptr, int *num2ptr);

int main(){
    int testone = 10;
    int testtwo = 20;
    printf("Before:test one is %i and test two is %i\n",testone,testtwo);
    swap(&testone,&testtwo);
    printf("After:test one is %i and test two is %i\n",testone,testtwo);
}

void swap(int *num1ptr, int *num2ptr){
    int hold = *num1ptr;
    *num1ptr = *num2ptr;
    *num2ptr = hold;
}