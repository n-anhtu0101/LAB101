#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float PlayGame() {
    float money = 0.0;
    int a = rand() % 10;
    int b = rand() % 10;
    int c = rand() % 10;
    printf("\nSlot Machine show : %d %d %d", a, b, c);
    if (a == b && b == c) {
        printf("You got a Big Win!");
        return money = 10.0;
    } else {
        if (a == b || b == c || a == c) {
            printf("\nYou Win $0.5");
            return money = 0.5;
        } else {
            printf("\nYou do not got anything!");
            return money;
        }
    }
}

void WriteFile(float money, char FileName[]) {
    FILE* file = fopen(FileName, "w");
    fprintf(file, "%f", money);
    fclose(file);
}

float ReadFile(char FileName[]) {
    float value = 0;
    FILE* file = fopen(FileName, "r");
    if (file == NULL) {
        printf("\nFile '%s' dose not exist!Created a new file with $10.0.", FileName);
        WriteFile(10.0, "SaveGame.txt");
        value = 10.0;
    } else {
        if (fscanf(file, "%f", &value) == 1) {
            if (value == 0.0) {
                printf("Your do not enough Money to Play! We gonna given you 10$ to play.");
                WriteFile(10.0, "SaveGame.txt");
                value = 10.0;
                fclose(file);
            } else {
                printf("\nFile '%s' exist! The value in File is: %.2f", FileName, value);
                fclose(file);
            }
        } else {
            WriteFile(10.0, "SaveGame.txt");
            value = 10.0;
            fclose(file);
        }
    }
    return value;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    float Money = ReadFile("SaveGame.txt");
    char ch;
    do {
        printf("\nYou have: $%.2f\n", Money);
        printf("\nChoose one of the following menu option:");
        printf("\n1) Play Game");
        printf("\n2) Save Game");
        printf("\n3) Cash Out");
        printf("\n4) SAVE AND EXIT ");
        printf("\nChoose option : ");
        ch = getchar();
        fpurge(stdin);

        switch (ch) {
            case '1':
                if (Money <= 0) {
                    printf("You do not have money enough to play!");
                    WriteFile(Money, "SaveGame.txt");
                    //remove("SaveGame.txt");
                    exit(0);
                } else {
                    Money = Money - 0.25 + PlayGame();
                }
                break;
            case '2':
            	//
                WriteFile(Money, "SaveGame.txt");
                printf("Your money had saved!");
                break;
            case '3':
                printf("\nThank you for playing, You have withdrawal $%.2f", Money);
                remove("SaveGame.txt");
                exit(0);
                break;
            case '4':
            	//
                WriteFile(Money, "SaveGame.txt");
                printf("Save and exit success. You can continue in next time");
                exit(0);
            default:
                printf("\nInvalid input, accept 1-3 only!\n");
                break;
        }
    } while (1);
    return 0;
}
