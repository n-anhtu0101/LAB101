#include <stdio.h>
#include <climits>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

/*
 * 
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
                printf("Out of range, Enter number [%d, %d]\n", Min, Max);
            }
        } else {
            printf("Invalid input,try again! Enter number [%d, %d]\n", Min, Max);
        }
    } while (1);
}

int main(int argc, char** argv) {
    do {
        printf(""); //THREADS
        int size = getInt("Please enter a number you want to check: ", INT_MIN, INT_MAX);

        //INPUT ARRAY WITH SIZE "size"
        int a[size];
        for (int i = 0; i < size; i++) {
            printf("a[%d] = ", i);
            a[i] = getInt("", INT_MIN, INT_MAX);
        }


//        bla bla code


//        printf("Press any key to continue\n");
//        char c = getch();

//        printf("Press esc to exit, enter to continue");
//        while(1){
//            char c = getch();
//            if (c == 27) exit(0); //27: esc
//            if (c == 13) break;   //13: enter
//        }
    } while (true);
    return 0;
}
