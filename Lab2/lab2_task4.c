/* For dynamic arrays, we need dynamic memory allocation, the malloc(), calloc(), and realloc() functions
in stdlib.h allow us to allocate memory. Once finished with allocation, we must free the memory back to
the OS using the free() function.

-> Forgetting to free memory is called a memory leak.
-> Attempting to access memory you are no longer allocated will either can a segmentation fault or just make you read garbage data
--> Reading unallocated data is called an invalid read
*/
#include <stdlib.h>
#include <stdio.h>

int main(){
    int* p = (int *)malloc(sizeof(int)); //this p pointer holds the address of the allocated block
    fprintf(stdout, "Value stored at address %p: %d\n", p, *p);
    *p = 1;

    fprintf(stdout, "Value stored at address %p: %d\n", p, *p);

    free(p); //passing the pointer to the block to be freed.
    fprintf(stdout , "Value stored at address %p: %d\n", p, *p);

}