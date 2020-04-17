#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc, char** argv) {
    int size;
    printf("Please enter size of array: ");
    scanf("%d", &size);
    int arr[size + 1];
    
    for (int i = 0; i < size; i++) {
        printf("Enter element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("The array after sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("\nPlease enter new value: ");
    int i = size;
    scanf("%d", &arr[size]);
    while (arr[i] < arr[i - 1] && i > 0) {
        int temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        i--;
    }
    printf("\n");
    printf("New array: \n");
    for (int i = 0; i < size + 1; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}
