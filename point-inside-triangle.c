#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
float area (int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs( (x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2)) / 2.0 );
}

int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq) {
    if (((x1 == x2) && (x1 == x3)) || ((y1 == y2) && (y1 == y3))) {
        return 0;
    }
      
    float a = area (x1, y1, x2, y2, x3, y3);
    
    float a1 = area (xp, yp, x2, y2, x3, y3);
    float a2 = area (x1, y1, xp, yp, x3, y3);
    float a3 = area (x1, y1, x2, y2, xp, yp);
    
    float aa1 = area (xq, yq, x2, y2, x3, y3);
    float aa2 = area (x1, y1, xq, yq, x3, y3);
    float aa3 = area (x1, y1, x2, y2, xq, yq);
    
    if ( a == a1 + a2 + a3 && a == aa1 + aa2 + aa3 ) {
        return 3;
    } else if ( a == a1 + a2 + a3 ) {
        return 1;
    } else if ( a == aa1 + aa2 + aa3 ) {
        return 2;
    } else {
        return 4;
    }
}
