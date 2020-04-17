#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>

/*
Bang cuu chuong
*/
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

int main(int argc, char** argv) {
    do {
    	//Enter bang cuu chuong n
        int n = getInt("Please enter a number(1-9):", 1, 9);
        
        //printf 
        for (int i = 1; i <= 10; i++) {
        	printf("%d x %d = %d\n", n, i, n * i);
    	}
        //
        printf("Press enter to continue, esc to exit.\n");
        
        while(1){
            char p = getch();
            if (p == 27) return 0; //27: esc
            if (p == 13) break;    //13: enter
        }
    } while (1);
    return 0;
}
