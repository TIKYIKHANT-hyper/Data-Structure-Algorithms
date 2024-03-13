//
// Created by TIKYI on 3/13/2024.
//
#include <stdio.h>
void printChars(const char *sPtr);
int main(){
    char string[] = "Printing Characters";

    printChars(string);
    return 0;
}

void printChars(const char *sPtr){
    for(; *sPtr != NULL; ++sPtr){
        printf("%c", *sPtr);
    }
}