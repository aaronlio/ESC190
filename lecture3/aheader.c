#include <stdio.h>
#include "aheader.h"

int multiply(int x, int y){
    int result = 0;
    for (int i=0; i<y; i++){
        result = add(result, x);
    }
    return result;
}

int add(int x, int y){
    int z = x + y;
    x = 200; // This is a copy of the x value, it gets the values 2 and 3 but not the locations of x and y in memory
    return z;
}