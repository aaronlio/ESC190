/*

Static arrays are fixed in size. Once a static array is allocated, it stays the same size forever. If
you need more space for your data, you will need to create a new static array and transfer all the
elements over one by one.

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int y[2] = {1,5};
    int x[3];

    for(int i = 0; i < 3; i++){
        x[i] = y[i];
    }
    x[2] = 9;
    
    // y[2] = 9;
    /* If we try to extend array y, which has a max of two elements, an indexing warning is thrown:
        "warning: array index 2 is past the end of the array (which contains 2 elements) [-Warray-bounds]"
    
    */

    fprintf(stdout, "Addresses of x 0: %p, 1: %p, 2: %p\n", x, x + 1, x + 2);
    // Remember from lectures, pointers to an array point to the location of the first element, and the following elements are
    // stored sequentially in memory, thus &x[0] is the same as &x.

    fprintf(stdout, "Values of x through dereferencing 0: %d, 1: %d, 2: %d\n", *x, *(x + 1), *(x + 2));
    // Using the * operator as to dereference

    fprintf(stdout, "Values of x through indexing 0: %d, 1: %d, 2: %d\n", x[0], x[1], x[2]);
    // Still prints the values of x, but in the more pythonic way

    //fprintf(stdout, "Indexing out of range: %d\n", x[3]);
    /*
    If we try to access an element out of range of the allocated array, we get an indexing warning:
        "warning: array index 3 is past the end of the array (which contains 3 elements) [-Warray-bounds]"
    */

   fprintf(stdout, "Addresses of y 0: %p, 1: %p,\n", y, y + 1);

}

/* Memory Table:

    x (pointer to x[0]) <--> 0x308808464 (Address of x[0]) <--> 1 (x[0]) <--> *x
    x + 1 <--> 0x308808468  <--> 5  <--> *(x+1)
    x + 2 <--> 0x30880846c  <--> 9  <--> *(x+2)

    y <--> 0x30dd86470  <--> 1 <--> *y
    y+1 <--> 0x30dd86474  <--> 5 <--> *(y+1)
*/

