//
// Created by TIKYI on 3/13/2024.
//
#include <stdio.h>

void cubefun(int *ref);

int main(){
    int num = 5;
    printf("Before passing , the value is %d\n", num);
    cubefun(&num);
    printf("After passing , the value is %d\n", num);
}

void cubefun(int *ref){
    *ref = *ref * *ref * *ref;
}