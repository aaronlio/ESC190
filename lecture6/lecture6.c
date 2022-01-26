//--------------------- Lecture 6 ------------------//

// ------------------ Pointers ---------------//
/* 

When we declare a variable, there is a unique place in computer memory (memory address) for storing the variable's value

    int x = 5;

x is an integer var - the value of 5 will be stored at the memory address of x

- Pointer vars store a memory address as their value
    - Declaring a point looks like this

        data_type *pointer_var_name;

    EX.
        int *y; -> y stores the address of an int


- The address operator (&) gives the memory address of a var.
    - &var_name gives the address of var_name

        int x = 5;
        int *y = &x; -> address of x stored in y
        int **z = &y -> address of y will be stored in z (double pointer)

- Use the %p formal specifier to print mem addresses

    printf("The address of x is: %p\n", &x);
    printf("The address of x is: %p\n", y);


            Z ------> address pointing to y
            Y ------> address pointing to x
            x ------> 5

- * is used to declare a poitner var and as an indeirection operator to access the value stored at an address (de-referencing)
    - int x = 5, *y = &x, **z = &y;

        printf("The value at &x is: %d\n", x);
        printf("The value at &x is: %d\n", *y);
        printf("The value at &x is: %d\n", **z);
        printf("The value at &x is: %d\n", *(&x));


- The indirection operator allows us to change the value sotred at the address the pointer point to:

        int x = 5;
        int *y = &x;
        *y = 10; --> same as x = 10;

    - Make sure the types left and right of the assigment operator (=) math
    
    - Avoid using the indirection operator on an uninitialized pointer var

        int *y; --> no initial value
        printf("%d\n", *y); --> undefined behaviour
        *y = 5; --> undefined behaviour

So:
    *var is "get the value that is at the memory address stored in var"
    &var is "get the memory address of var"

Ex) 
    1)
        
        int a = 2, b = 3, *c, *d;
        c = &a; --> c points to a
        d = c; --> d also points to a

        *d = b; --> assign value of b to a

        c = &b; --> c points to b
        *d = 6; --> change value of a to 6

        *c = *d; --> assign value of a to b

*/

// ------------------ Vars as Fcn Args ---------------//
/*

// in no_change(int a){}

void no change(int a){
    a = 2;
    return a;
}

int main(){
    int x = 5;
    no_change(x);
    // x = no_change(x);
    return 0;
}

- Passing an integer var as an argument to a fcn:
    - The fcn gets a copy of the value

void no change(int *a){
    *a = 2;
    return a;
}

int main(){
    int x = 5;
    int *x_ptr = &x;
    yes_change(x_ptr);
    // yes_change(&x);
    return 0;
}


- Passing an integer ptr var

*/

//-------------Pointers and Arrays-------------//
/*

We pass char arrays to string.h fcns that expect char* because array var names are pointers to the first element of the array

        in my_array[] = {1,2,3,4,5};
        *my_array = 5; //is the same as my_array[0] = 5;
        int *array_ptr = my_array; // don't need to use &my _array

    - Therefore, int *array_ptr = &my_array[0];

- Note you cant assign new values to array var names
        int diff_array[] = {6,7,8};
        my_array = diff_array; ---> not allowed

- We can add/subtract to/from pointers to access other elements:
    - If array_pr points to my_array[j],
    then array_ptr + k fpoint to my_array[j+k]

        int my_array[] = {1,2,3}, *array_ptr;
        array_ptr = my_array; ---> array_ptr = &my_array[0]
        array_ptr = array_ptr+2; ---> array_ptr = &my_array[2]

        *(my_array+3) = 5; ---> my_array[3] = 5;
        *(array_ptr+2) = 6; --> my_array[3] = 5;


    - When iterating through array elements in loops, (ie. i++):

        my_array[i], *(my_array + i), or *(array_ptr+i)


- Subtract pointers to get the distance (unit = number of elements)

        int my_array[] = {1,2,3};
        int *array_ptr, *another, ptr_sub;

        array_ptr = my_array + 3; --> array_ptr = &my_array[3];
        another = array_ptr - 2: --> another = &my_array[1];

        ptr_sub = array_ptr - another; --> ptr_sub = 2

*/

//--------------- Dynamic Memory/Storage Allocation ------------//
/*

Refers to allocating memory during program execution
    - Nomrally, mem for vars is static
        - Automatically freed as functions return
    - Dynamically allocated memory can shring/grow in size throughout progra
        - Is reserved and lingers until we free it ourselves
        - Keep track of any allocated memory until it is freed

Allocating memory:
    - Allows us to make arrays, etc., that can change size (recall Python's list.append())
    - Allows us to return addresses of new values generated in a function

Freeing memory:
    - Free any allocated memory before the program ends to avoid memory leaks
    - Do not try to access memory that has been freed



*/

//------------ #include <stdlib.h> ---------------//

/*

void *malloc(size_t size);
    - Allocates a block of uninitilized memory, size specifies the block size

void *calloc(size_t nmemb, size_t size);
    - Allocates a block of memory, nmemb * size, each initialized to 0

- Return type void * means it returns a generic pointer, can be cast to int *, char *, etc

- If a memory block can't be allocated a null pointer is return
    - Good habit to have an if statement to check for this before use

void *realloc(void *ptr, size_t size);
    - Resizes the block of memory pointed to by ptr
    - ptr should point to a mem block from prior malloc(), calloc(), realloc(),
        - if ptr is null, this becomes a malloc() call

    - New size of mem block is size
        - if size is 0, this becomes a free() call
        - Expanding, no initialization of added mem, data may be copied to another area of memory
        - Shrinking: done-in place, no movement of data, update pointers to be safe

void free(void *ptr);
    - Frees the memory block ptr points to. Nothing happens if ptr is a null pointer

*/

// ------------ Example ---------------//
/*

        int n = 5;
        int *ptr_a = mallow(n * sizeof(int)); --> treat like array[5]
        int *ptr_b = calloc(n, sizeof(n)); --> treats like array[5] = {0}
        int *another = ptr_b; --> another and ptr_b point to the same value

        ...stuff...

        free(ptr_a);
        free(another); --> same memory block as ptr_b, similar to free(ptr_b)
*/

