#include <cstdlib>
#include <stdio.h>
#include <time.h>


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

int random(int minN, int maxN) {
    return rand() % (maxN + 1 - minN);
}

int main(int argc, char** argv) {
    srand((int) time(0));
    
    int size = getInt("Please enter number: ", 0, 100);
    int a[size];
    
    printf("New array: \n");
    for (int i = 0; i < size; i++) {
        a[i] = random(0, 255);
        printf("a[%d]: %d\n", i, a[i]);
    }
    
    printf("\nFind letters corresponding to the integer equivalent of letter\n");
    for (int i = 0; i < size; i++) {
        if ((a[i] > 64 && a[i] < 91) || (a[i] > 96 && a[i] < 123)) {
            printf("a[%d]: %c\n" , i, a[i]);
        }
        printf("a[%d]: %d\n", i,a[i]);
    }
    return 0;
}
