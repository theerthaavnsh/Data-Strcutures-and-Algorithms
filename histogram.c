#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char inputString[100];
    int frequency[26] = {0}; 

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // calculate character freq //
    for (int i = 0; inputString[i] != '\0'; i++) {
        char currentChar = tolower(inputString[i]);
        if (isalpha(currentChar)) {
            int index = currentChar - 'a';
            frequency[index]++;
        }
    }

    // display the character freq //
    printf("Character Frequency Histogram:\n");
    for (int i = 0; i < 26; i++) {
        char currentChar = 'a' + i;
        if (frequency[i] > 0) {
            printf("%c: ", currentChar);
            for (int j = 0; j < frequency[i]; j++) {
                printf("*");
            }
            printf(" (%d)\n", frequency[i]);
        }
    }

    return 0;
}

