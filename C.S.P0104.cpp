#include <cstdlib>
#include <stdio.h>
#include <climits>
#include <cstdint>
#include <cmath>

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

bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    do{
        int a;
        a = getInt("Please enter a number you want to check: ", 0, 5000);
        for(int i = 2; i <= a/2; i++){
            if(isPrime(i) == true){
                if(isPrime(a - i) == true){
                    printf("%d = %d + %d\n", a, i, a-i);
                }
            }
        }
        printf("Press Enter to continue\n");
        char c = getchar();
    }while(true);
    return 0;
}
