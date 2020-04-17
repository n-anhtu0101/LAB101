#include <stdio.h>
#include <climits>
#include <string.h>
#include <stdlib.h>

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

void decToBinary(int n) {
    int size = 0;

    int *arr = (int*) malloc(size * sizeof (int)); //cap phat ban dau cua no la 0 byte
    
    while (n > 0) {
        arr = (int *) realloc(arr, ++size * sizeof (int));
        //Hàm này thuc hien cap phát vùng nho moi cho con tro "arr". Vùng nho moi dó se có kích thuoc moi là ++size * sizeof (int) bytes.
        arr[size - 1] = n % 2;
        n = n / 2;
    }

    printf("Binary number: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    free(arr);
}

int main(int argc, char** argv) {
	
    printf("Convert Decimal to Binary program\n");
    do {
        int n = getInt("Enter a positive number: ", 1, INT_MAX);//INT_MAX: 2,147,483,647 = 2^31 - 1
        decToBinary(n);
        printf("\nPress any key to do another conversion.\n");
        char c = getchar();
    } while (true);
    return 0;
}
