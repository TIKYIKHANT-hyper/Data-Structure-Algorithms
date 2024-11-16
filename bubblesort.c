#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define displayName(var) #var
#define SIZE 14

void arrDisplay(int arr[], int size);
void bubbleSort(int arr[], int size);
int main() {
    srand(time(NULL));
    int arrayOne[SIZE];
    for(int i = 0; i < SIZE; i++) {
        arrayOne[i] = rand() % 100;
    }
    arrDisplay(arrayOne, SIZE);
    bubbleSort(arrayOne, SIZE);
    arrDisplay(arrayOne, SIZE);
    return 0;
}

void arrDisplay(int arr[], int size) {
    int counter = 0;
    printf("%s = ",displayName(int arr[]));
    printf("[");
    while(counter < size) {
        printf("%d", arr[counter]);
        if(counter < size - 1) {
            printf(",");
        }
        counter++;
    }
    printf("]\n");
}

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1 ; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}