#include <stdio.h>

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
                printf("Out of range, Enter number in [%d, %d]\n", Min, Max);
            }
        } else {
            printf("Invalid input,try again! Enter number <= %d\n", Max);
        }
    } while (1);
}

int main(int argc, char** argv) {
    int size = getInt("Please enter size of array:", 1, 1000);
    int arr[size];

    //Enter size
    for (int i = 1; i <= size; i++) {
        printf("Element[%d] =", i);
        arr[i] = getInt("", 1, 1000);
    }
    
    //Output array
    for (int i = 1; i <= size; i++) {
    	printf("%d\t", arr[i]);
	}
	printf("\n");
	
    //Enter index that you want to swap
    int i1;
    int i2;
    printf("Swap two elements: \n");
    i1 = getInt("", 1, 5);
    i2 = getInt("", 1, 5);
    printf("\n");
    
    //SWAP
    //1  2  5  4 
    int temp = arr[i1];
    arr[i1]  = arr[i2];
    arr[i2]  = temp;
    
    //re - output
    printf("Array after swapping:\n");
    for (int i = 1; i <= size; i++) {
    	printf("%d\t", arr[i]);
	}
    return 0;
}
