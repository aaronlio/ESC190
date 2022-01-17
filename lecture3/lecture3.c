/*------------------------------ LECTURE 3 ------------------------*/

// ------------ Static Arrays ------------//

/* Arrays are declared with the type of elements in the array and the number of elements:

    int my_array[10];

You can access the elements by [indexing] --> Zero indexed
    
    my_array[0] = 5;

Indexes range from 0 to (number of elements-1)
    - Undefined behaviour if index is out of bounds

You can also combine declaration with initialization:

    int my_array[] = {1,2,3,4,5,6,7,8,9,10};

When initializing, the {} cannot be empty or contain too many elements
    - if too few, the remaining elements are set to zero
    - int my_array[10] = {0} --> sets all elements to zero

Passing an array allows modification of the original array
    - The array name passes the address

#define can be used for common variables
*/ 

// ------------------ Strings --------------- //
/*
Sequences of characters - no string type in C

Strings are stored as character arrays that end with '\0' (null character)
    - Null character has integer value 0 (evaluates to False)
    - "C" is a string, 'C' is a character

When storing the string, make sure there is room for '\0'
    - To store 'hello' --> see slideshow

Declaration of a string as a character array vs character pointer
    - char my_array[] = "hello world"; //mutable
    - char* my_ptr = "hello world"; //immutable --> a string literal/constant
    - '\0' is added in these cases

Character pointers can point to character arrays
*/

//------------ String Arrays + Functions ------------//
/* char* indicates the string will be modified by the function
    - const char* indicates it is okay to use a string literal

char* strcpy(char* s1, const char* s2);
    - Copies s2 into s1 (doesn't check size of s1: MAKE SURE IT'S NOT OVER THE MEM-LIMIT)
    - Returns s1, whose value is modified

size_t strlen(const char* s);
    - Returns the length of the string s (warning: doesn't count '\0')
    - size_t is an unsigned integer type (treat as an integer)

char* strcat(char* s1, const char* s2);
    - Copies s2 to the end of s1
    - Returns s1

int strcmp(const char* s1, const char* s2);
    - Returns an integer that indicates if s1 is >, =, or <, compared to s2
    - Based on lexicographical order (dictionary order)

*/