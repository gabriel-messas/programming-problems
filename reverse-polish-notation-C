#include <stdio.h> 
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

void MathChallenge(char * str) {
  // printf("%s\n", str);

  int* list = malloc(1 * sizeof(int));
  int index = -1;

  while (1) {
    char current[strlen(str)];
    if (sscanf(str, "%s", current) != 1) {
      printf("%d\n", list[index]);
      return;
    }

    if (current[0] >= '0' && current[0] <= '9') {
      index++;
      list[index] = atoi(current);
      list = realloc(list, (index + 2) * sizeof(int));

      str += strlen(current) + 1;
    } else if (strlen(current) == 1) {
      int num2 = list[index];
      index--;
      int num1 = list[index];

      switch (current[0]) {
        case '+':
          list[index] = num1 + num2;
          break;

        case '-':
          list[index] = num1 - num2;
          break;

        case '*':
          list[index] = num1 * num2;
          break;

        case '/':
          list[index] = num1 / num2;
          break;
      }

      str++;
      if (str[0] == ' ') {
        str++;
      }
    }

  }

}

int main(void) { 
   
  // keep this function call here
  MathChallenge(coderbyteInternalStdinFunction(stdin));
  return 0;
  
}
