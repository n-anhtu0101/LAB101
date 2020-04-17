#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
                printf("Out of range, Enter number [%d, %d]\n", Min, Max);
            }
        } else {
            printf("Invalid input,try again! Enter number [%d, %d]\n", Min, Max);
        }
    } while (1);
}

//OUTPUT N PRIME
int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void displayPrime() {
    printf("\n");
    int n;
    n = getInt("Number of primes:", 1, 50);
    int count = 0;
    int i = 1;
    while (count < n) {
        i++;
        if (isPrime(i) == 1) {
            printf("%d  ", i);
            count++;
        }
    }
    printf("\n");
}

//CHECK N IS FIBONANCI???
int isFibo(int n) {
    int f0 = 0;
    int f1 = 1;
    if (n == f0 || n == f1) return 1;
    int f3 = f0 + f1;  //=1
    //n = 7
    while (f3 < n) {
        f0 = f1;       //1	1	2	3
        f1 = f3;       //1	2	3	5
        f3 = f0 + f1;  //2	3	5	8
        if (f3 == n) return 1;
    }
    return 0;
}

void displayFiBo() {
	printf("\n");
    int n = getInt("Enter test:", 1, 1000);
    if (isFibo(n) == 1) {
        printf("It's a Fibonacci term\n");
    } else {
        printf("It's not a Fibonacci term\n");
    }
    printf("\n");
}

//TOTAL DIGIT
void getSum() {
	printf("\n");
    int n = getInt("Enter an integer:", -1000, 1000);
    
    if (n < 0) {
        n = n*-1;
    }

    int num = n;
    int sum = 0;
    //123
    for (num = n; num > 0; num /= 10) {
        int digit = num % 10; //3  
        sum += digit;		  //3  
    }
    printf("Sum Digit: %d", sum);
    printf("\n");
}

int main(int argc, char** argv) {
    do {
        printf("---MENU---\n");
        printf("1-The first primes\n");
        printf("2-Fibonacci element\n");
        printf("3-Sum of digits\n");
        printf("Choose an option: ");
        int n = getInt("", 1, 3);
        switch (n) {
            case 1:
                displayPrime();
                printf("\n");
                break;
            case 2:
                displayFiBo();
                break;
            case 3:
                getSum();
                printf("\n");
                break;
        }
    } while (1);
    return (EXIT_SUCCESS);
}
