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
    
    
    *x = (int *) realloc(*x, ((*n+1) * sizeof(int)));
    (*x)[*n] = val;
    *n += 1;


}
/*int main() { 
    int len = 5;
    int *n = &len;
    
    int *arr = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < *n; i++) {
        arr[i] = i;
    }
    int **x = &arr;

    append(x, n, 69);

    printf("%d\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("%d ", *(*x + i));
    }
    free(arr);
 }*/
// *n is number of items in list
// *x, **x[0] is the first element (*x is the pointer to the first) of the list, *(x+(*n+1)), **x[*n+1] is the last
// x is the pointer to the pointer of the first element of the list.
// val is value to be appended