/************************** LECTURE 1 **************************/
/* C is an popular, industry standard language that is fast and permissive. Even Python uses C!
C programs consist of one or more .c files and/or .h files.
It is written in a text editor or an IDE. 
There must be a main() function for execution.

Python is an interpreted language, C is a compiled language.

To run C code, you need a compiler (gcc) to automate:
    -> Pre-processing, making modification(s) to the program
    -> Compiling this program to generate an executable file
    -> Linking any extra code ie. Libraries */

/* programs start with directives, #include <stdio.h> to use the printf() function*/

//////////Function Definition structure: ///////
/* return_type function_name (parameter_type parameter_name){
    function_body_statement
} 
*/

// Statements end with a semicolon ;
// Return statement terminates the fucntion and can return a value
// Single line comments -> //

/* 
Using command line, navigate to the directory where the files are located,
compile: gcc filename -o output_filename
run: ./output_filename

Using an IDE:
Select the project in the workspace
Build -> Build and run 
*/

            // C is a strictly typed language //

/* 
Declare variables (name and dtype) before use
Remember to initialize your variables by assigning starting values
Dtypes are defined by the C standard... but their exact specifications depend on the operating system and hardware

char -- 1 byte -- characters -- %c, %s
int -- 4 bytes -- integers -- %d
float -- 4 bytes -- %f
double -- 8 bytes -- %f
*/

            // Printing formatted strings

/* printf() is a formatted string
We can print using format specifiers with many formatting options (.2f% for 2 decimals) 
*/

            // Explicit Casting in C

#include <stdio.h>

int main()
{
    int digit = 4;
    printf("Hello, World! This is a native C program compiled on the command line.\n");
    printf("This is the number %d\n", digit);
    printf("This is the number %f\n", (float) digit);
    return 0;
}

