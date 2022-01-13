//---------------------------------------- Lecture 2 -----------------------------------//
// Type-casting //

/* Converting from one type to another can be done implicitly or explicitly, it may not 
always be safe (data loss, rounding issues).

*/ 
//Extras// 
/*
Avoid overflow and using unitialized variables - the code will appear to work, but 
generate unexpected value or terminate early

1 + 'c' is possible, check the ASCII table for what the sum should be

fprintf(stdout, "Hello!"); is like printf("Hello!");

signed (default) vs unsigned integers 
    - Left-most bit of a signed interger is used to indicate if it's positive or negative
    - unsigned has larger max values but can only store position values
*/


//----------- Operators in C -----------------//
/* Increment (++) and decrement (--) modify operands, + and - don't, 
use += and -= to combine addition and subtraction with assignment
++var increments before use, var++ increments after use.

&, |, and ^, <<, and >> are bit operators (not the same as &&, ||, and pow)
*/

//----------- Operator Precendence ----------//
/* 
1. ++, --
2. *, /, %
3. +, -
4. =, *=, /=, +=, -=

Use () if you can't remember, also improves readability
*/

//----------- Conditional Statements ----------//

//---------IF---------//
/* if (expression) {
    statements
} else if (expression) {
    statements
} else {
    statements
}

Non-zero = true, zero is false

Only one of the blocks will execute (the first True), can use sequential if statements if multiple checks needed
-> Else if is a nested if.


//---------FOR---------//

for (expr1; expr2; expr3){
    statements
}

expr1 is an initialization step, occurs one at start (i = 0)
expr2 controls termination, looping stops when False (i <= 5)
expr3 operation occurs at the end of each iteration (i++)
for loops that are defined within the for loop only exist within the scope of the for loop

//---------WHILE---------//
while (expression) {
    statements
}

Avoid infinite loops, looping 1 too many/few times
*/

//------------------ SAMPLE CODE ---------------//
#include <stdio.h>

int main(){

    printf("1+ 'c' is %c\n", 1 + 'c');
    printf("1+ 'c' is %d\n\n", 1 + 'c');

    printf("2/5 evaluates to", 2/5);
    float res = 2/5;
    printf("Assigning to a float gives you");
}

//------------------ CODE ORGANIZATION ---------------//
/* Functions must be defined before their use
    - Single .c file for small programs
        - Full definition above main()
        - Prototype above main() function, definition below main
    
    - Multiple .c files - modularity, grouping of related function
        - Prototype in header file, full definition in another .c file
            - #include "header_filename.h"
            - <> instead of "" for header files of C standard libraries



-------Options for single file-------
1. 
#include directives
void adele(){
    statements
}
main()

2. 
void adele(); <-- Prototype!

main()

void adele(){
    statements
}


-------For multi-file-------
./main.c
#include directives
#include "adele.h"

main(){

}

./adele.c
#include directives
#include "adele.h"

void adele(){
    statements
}

./adele.h
void adele();
*/


