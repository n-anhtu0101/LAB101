#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>

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

void sum(int n) {
    int num = n;
    int sum = 0;
    
    for (num = n; num > 0; num /= 10) {
        int digit = num % 10;
        sum += digit;
    }
    printf("Sum Digit: %d", sum);
}

int main(int argc, char** argv) {
    char c;
    printf("Sum Digit Program\n");
    do {
        int n = getInt("Enter integer: ", INT_MIN, INT_MAX);
        if (n < 0){
            n = n * -1;
	}
        sum(n);
        printf("\nPress any key to continue.");
        c = getch();
    } while (true);
    return 0;
}
