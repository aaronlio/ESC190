#include <stdlib.h>
#include <stdio.h>

/*
    <*x> refers to a dynamically allocated integer array of size <*n> * sizeof(int).
    Modify <*x> such that it has val added to the end.
    
    The modified array should be of length <*n> + 1. 
    Modify <*n> such that it is updated to be the value of the new length of the array <*x>.
        
    HINT: you may find the function realloc (...) helpful
    */

void append(int** x, int* n, int val){

    
    printf("%p\n", x);
    *n += 1;
    printf("%d\n", *n);
    x = (int **) realloc(x, ((*n) * sizeof(int)));
    *(x+*n) = &val;

    printf("%d\n", (*(*(x+*n))));
}
int main(){
    int list[] = {1,2,3};
    int* ptr = list;
    int **x = &ptr;
    int count = sizeof(list)/sizeof(list[0]);
    int* n = &count;
    x = (int **) malloc(((*n) * sizeof(int)));
    
    int val = 5;

    append(x, n, val);

    return 0;
}
// *n is number of items in list
// *x, **x[0] is the first element (*x is the pointer to the first) of the list, *(x+(*n+1)), **x[*n+1] is the last
// x is the pointer to the pointer of the first element of the list.
// val is value to be appended