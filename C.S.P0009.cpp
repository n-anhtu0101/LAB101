#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int checkint(char*Msg, int Min, int Max) {
    char ch;
    int Number, check;
    do {
        printf("%s", Msg);
        fflush(stdin);
        check = scanf("%d%c", &Number, &ch);
        if (check == 2 && ch == '\n') {
            if (Number >= Min && Number <= Max)return Number;
            else printf("\n out of range");

        } else
            printf("\n invalid input,try again!");
    } while (1);
}

int main(int argc, char** argv) {
    int size = checkint("Please enter size of array: ", 1, 1000);
    int arr[size];
    
    //input element
    for (int i = 0; i < size; i++) {
        printf("Element[%d] = ", i);
        arr[i] = checkint("", 1, 1000);
    }
    
    //find smallest value of array
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
	
	//output smallest value and index of array
    for (int i = 0; i < size; i++) {
        if (arr[i] == min) {
        	printf("Smallest %d at: %d\n", i, arr[i]);
        }
    }
    return 0;
}
