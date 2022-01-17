#include <stdio.h>
#include "aheader.h"

int main(){
    int x = 2;
    int y = 3;
    fprintf(stdout, "%d\n", multiply(x,y));
    fprintf(stdout, "Value of x: %d\n", x);
}
