#include <cstdlib>
#include <stdio.h>
#include <string.h>

int main() {
    char c;
    do {
        char str[100], word[100];
        int i, index, found = 0;
        printf("Please enter main string: ");
        gets(str);
        
        printf("Please enter substring: ");
        gets(word);
        
        while (str[index] != '\0') {
            if (str[index] == word[0]) {
                i = 0;
                found = 1;
                while (word[i] != '\0') {
                    if (str[index + i] != word[i]) {
                        found = 0;
                        break;
                    }
                    i++;
                }
            }
            if (found == 1) {
                break;
            }
            index++;
        }

        if (found == 1) {
            printf("Starting position of the substring in the main string: %d\n", index);
        } else {
            printf("'%s' is not found.\n", word);
        }
        
        printf("Enter to continue");
        c = getchar();
    } while (true);
}
