#include <stdio.h> 
#include <string.h>
#include <malloc.h>

void ArrayChallenge(char * strArr[], int arrLength) {
  int** nodeParentChildrenCount = calloc(3, sizeof(int*));
  nodeParentChildrenCount[0] = calloc(1, sizeof(int));
  nodeParentChildrenCount[1] = calloc(1, sizeof(int));
  nodeParentChildrenCount[2] = calloc(1, sizeof(int));
  int currSize = 0;

  for (int i = 0; i < arrLength; i++) {
    int c, p;
    sscanf(strArr[i], "(%d,%d)", &c, &p);

    int j;
    for (j = 0; j < currSize; j++) {
      if (nodeParentChildrenCount[0][j] == c) {
        nodeParentChildrenCount[1][j]++;
        break;
      }
    }

    if (j == currSize) {
      currSize++;
      nodeParentChildrenCount[0] = realloc(nodeParentChildrenCount[0], currSize * sizeof(int));
      nodeParentChildrenCount[1] = realloc(nodeParentChildrenCount[1], currSize * sizeof(int));
      nodeParentChildrenCount[2] = realloc(nodeParentChildrenCount[2], currSize * sizeof(int));

      nodeParentChildrenCount[0][currSize - 1] = c;
      nodeParentChildrenCount[1][currSize - 1]++;
    }

    for (j = 0; j < currSize; j++) {
      if (nodeParentChildrenCount[0][j] == p) {
        nodeParentChildrenCount[2][j]++;
        break;
      }
    }

    if (j == currSize) {
      currSize++;
      nodeParentChildrenCount[0] = realloc(nodeParentChildrenCount[0], currSize * sizeof(int));
      nodeParentChildrenCount[1] = realloc(nodeParentChildrenCount[1], currSize * sizeof(int));
      nodeParentChildrenCount[2] = realloc(nodeParentChildrenCount[2], currSize * sizeof(int));

      nodeParentChildrenCount[0][currSize - 1] = p;
      nodeParentChildrenCount[2][currSize - 1]++;
    }
  }

  if (currSize < arrLength) {
    printf("false\n");
    return;
  }

  for (int i = 0; i < currSize; i++) {
    if (nodeParentChildrenCount[1][i] >= 2) {
      printf("false\n");
      return;
    }
    if (nodeParentChildrenCount[2][i] > 2) {
      printf("false\n");
      return;
    }
  }

  printf("true\n");
  return;

}

int main(void) { 
   
  // keep this function call here
  char * A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  ArrayChallenge(A, arrLength);
  return 0;
    
}
