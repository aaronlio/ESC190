#include <stdlib.h>
#include <stdio.h>

int main(){
    int* p = (int *)malloc(sizeof(int));
    int* q = (int *)malloc(sizeof(int) * 2);
    *p = 1;
    *q = 10;

    q = p;
    printf("*p: %d, *q: %d, p: %p, q: %p ", *p, *q, p, q);

    free(q);
    // Since the address q was changed to the address p, there is no pointer to the memory previously pointed to by q, so it can't be freed.
    free(p);

}