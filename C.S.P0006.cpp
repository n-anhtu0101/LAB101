#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int getInt(char*Msg, int Min, int Max) {
    char ch;
    int Number, check;
    do {
        printf("%s", Msg);
        fflush(stdin);
        check = scanf("%d%c", &Number, &ch);
        if (check == 2 && ch == '\n') {
            if (Number >= Min && Number <= Max) {
                return Number;
            } else {
                printf("Out of range, Enter number <= %d\n", Max);
            }
        } else {
            printf("Invalid input,try again! Enter number <= %d\n", Max);
        }
    } while (1);
}
// 8 9 5 6 2
// 5 9 8 6 2
// 2 9 8 6 5
// 
// 
void sort(int arr[], int size, int value){
    int tg;
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] * value > arr[j]* value){
                tg = arr[i];
                arr[i] = arr[j];
                arr[j] = tg;        
            }
        }
    }
}

void show(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main(int argc, char** argv) {
    int size = getInt("Please enter size of array:", 1, INT_MAX);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element[%d]:", i);
        arr[i] = getInt("", INT_MIN, INT_MAX);
    }
    
    printf("\nThe array sorted in ascending:\n");
    sort(arr, size, 1);
    show(arr, size);
    
    printf("\nThe array sorted in descending:\n");
    sort(arr, size, -1);
    show(arr, size);
    return 0;
}
