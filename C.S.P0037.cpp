#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <conio.h>

using namespace std;

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

int isPerSquare(int n){
    if(sqrt(n)- floor(sqrt(n)) == 0){
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    printf("Check square Number Program\n");
    while (1) {
        int n;
        n = getInt("Enter a positive integer = ", 1, INT_MAX); //2^31 - 1;
        if(isPerSquare(n) == 1){
            int k = sqrt(n);
            printf("%d is a square number %d = %d * %d\n", n, n , k, k);
        }else{
            printf("%d is not a square number\n", n);
        }
        printf("Press any key to continue.\n\n");
        char ch = getch();
        if (ch == 27) break;
    }
    return (0);
}
