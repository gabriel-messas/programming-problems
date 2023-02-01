#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'getUniqueCharacter' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int getUniqueCharacter(char* s) {
    int exit = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == -1) {
            continue;
        }
        for (int j = strlen(s)-1; j > i; j--) {
            if (s[i] == s[j]) {
                s[j] = -1;
                while (j > i+1) {
                    j--;
                    if (s[i] == s[j]) {
                        s[j] = -1;
                    }
                }
                break;
            }
            if (j == i +1) {
                return j;
            }
        }
    }
    return -1;
}
