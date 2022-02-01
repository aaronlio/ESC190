#include <stdlib.h>
#include <stdio.h>
int main(){
    int x = 0;
    int y = 0;

    int* ptr_x = &x;
    int* ptr_y = &y;
    int** pptr_x = &ptr_x;
    int** pptr_y = &ptr_y;

    fprintf(stdout, "x contains the value %d at location %p\n", *ptr_x, ptr_x);
    fprintf(stdout, "y contains the value %d at location %p\n", *ptr_x, ptr_x);

    //printf("%p, %p", pptr_x, pptr_y);

    //if they have the same value, x and y will share the same location in memory





}