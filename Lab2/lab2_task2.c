#include <stdlib.h>
#include <stdio.h>
int main(){
    int x = 0;
    int y = x;

    int* ptr_x = &x;
    int* ptr_y = &y;
    int** pptr_x = &ptr_x;
    int** pptr_y = &ptr_y;

    fprintf(stdout, "x contains the value %d at location %p\n", *ptr_x, ptr_x);
    fprintf(stdout, "y contains the value %d at location %p\n", *ptr_x, ptr_x);

    fprintf(stdout, "pptr_x: %p, pptr_y: %p\n", pptr_x, pptr_y);

    fprintf(stdout, "ptr_x: %p, ptr_y: %p\n", ptr_x, ptr_y);
    //if they have the same value, x and y will share the same location in memory





}
