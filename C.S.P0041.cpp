#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <climits>
/**/

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

int maxValue(int size, int arr[]) {
    int max = arr[0];
    // 2 3 5 1 
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void evenValue(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
}

int main(int argc, char** argv) {
    int size;

    size = getInt("Enter a number of element size = ", 1, 100);
    int arr[size];
    
    for (int i = 0; i < size; i++) {
        printf("Element %d = ", i);
        arr[i] = getInt("", 1, 1000);
    }
    
    //output element
    printf("Array element: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nThe max is : %d", maxValue(size, arr));

    printf("\nThe even value is : ");
    evenValue(size, arr);
    return (0);
}
