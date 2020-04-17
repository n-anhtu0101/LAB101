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

int sum(int a[], int size, int value){
	int sum = 0;
	for(int i = 0; i < size; i++){
		if(a[i] % 2 == value){
			sum += a[i];
		}
	}
	return sum;
}
int main(int argc, char** argv) {
    printf(""); //THREADS
    int size = getInt("Please enter a number you want to check:", INT_MIN, INT_MAX);
    int a[size];
    for (int i = 0; i < size; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Sum odd  = %d\n", sum(a, size, 1));
    printf("Sum even = %d\n", sum(a, size, 0));
    return 0;
}
