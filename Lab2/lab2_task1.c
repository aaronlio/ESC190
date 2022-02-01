#include <stdlib.h>
#include <stdio.h>
int main(){
    int x = 0;
    int* ptr = &x; //in this line, the * operator is declaring the type of ptr to be a "pointer to an int (x)".
    fprintf(stdout, "x contains the value %d at location %p\n", *ptr, ptr); 
    // in the above line, * is a dereferencing operator, giving us the value stored at the memory address of ptr.
}