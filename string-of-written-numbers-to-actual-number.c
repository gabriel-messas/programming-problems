#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int isNumber(char* str) {
  char* numbers[10] = { "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine" };

  for (int i = 0; i < 10; i++) {
    if (strcmp(str, numbers[i]) == 0) {
      return i;
    }
  }

  return -1;
}

int isSignal(char* str) {
  char* signals[] = { "plus", "minus" };

  if (strcmp(str, signals[0]) == 0) {
    return 1;
  } else if (strcmp(str, signals[1]) == 0) {
    return -1;
  }

  return 0;
}

char* buildExtense(char* number) {
  char* result = malloc(1 * sizeof(char));
  char* numbers[10] = { "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine" };

  if (number[0] == '-') {
    result = realloc(result, 9 * sizeof(char));
    strcpy(result, "negative");

    for (int i = 1; i < strlen(number); i++) {
      char* digit = numbers[number[i] - '0'];
      result = realloc(result, (strlen(result) + strlen(digit)) * sizeof(char));
      strcat(result, digit);
    }
  } else {
    for (int i = 0; i < strlen(number); i++) {
      char* digit = numbers[number[i] - '0'];
      result = realloc(result, (strlen(result) + strlen(digit)) * sizeof(char));
      if (i == 0) {
        strcpy(result, digit);
      } else {
        strcat(result, digit);
      }
    }
  }

  return result;  
}

void StringChallenge(char * str) {
  char* reading = malloc(1 * sizeof(char));
  char* temp = malloc(6 * sizeof(char));

  int current = 0;
  int signal = 1;

  while (1) {
    if (str[0] == '\0') {
      current += (atoi(reading) * signal);
      free(reading);

      char* result = malloc(strlen(str) * sizeof(char));
      sprintf(result, "%d", current);

      printf("%s\n", buildExtense(result));
      return;
    }

    for (int i = 3; i <= 5; i++) {
      strncpy(temp, str, i);

      int num = isNumber(temp);
      if (num > -1) {
        char res[2];
        sprintf(res, "%d", num);
        if (strlen(reading) == 0) {
          strcpy(reading, res);
        } else {
          strcat(reading, res);
        }
        reading = realloc(reading, (strlen(reading) + 1) * sizeof(char));

        str += strlen(temp);
        free(temp);
        temp = malloc(6 * sizeof(char));
        break;
      }

      int sign = isSignal(temp);
      if (sign != 0) {
        current += (atoi(reading) * signal);
        free(reading);
        reading = malloc(1 * sizeof(char));
        signal = sign;

        str += strlen(temp);
        free(temp);
        temp = malloc(6 * sizeof(char));
        break;
      }

      continue;
    }
  }
  

}

int main(void) { 
   
  // keep this function call here
  StringChallenge(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
