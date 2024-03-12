#include <stdio.h>

int main(){
    int *ptr = NULL;
    int num = 6;
    ptr = &num;
    printf("%d\n", *ptr);
    printf("The address is %p , The number is %p \n", &num,ptr);
    printf("The value of num is %d and the value of *ptr is %d\n", num, *ptr);
    printf("*&ptr = %p \n &*ptr = %p\n", *&ptr, &*ptr);
    return 0;
}