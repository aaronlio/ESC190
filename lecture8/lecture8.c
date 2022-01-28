//--------------------- Lecture 8 ------------------//

// --------- Struct example from last lecture ---------//

/*

        struct Point{
            double x;
            double y;
        };

Practice: write:
    double euclidiean_dist(struct Point p1, struct Point p2){
        //gets the distance between the points
    }


        typedef struct FancyList{
            int* ptr;
            int max_el; //max # of elements
            int count_el; //current # of elements
        } Fancylist;

Write functions to 
    - set up a FancyList variable with an empty list that holds max_el = n, dynamically allocate for ptr
    - when appending, check if the list if full and resize to store max_el*2 elements
    - Print the list contents

*/

// --------- Dynamic memory for strings ------------/
/*

        int n = 6;
        char *mystring = malloc(n+1); // sizeof(char) is 1 (5 letters), +1 for '\0'
        strcpy(mystring, "Ar"); // initialize the string array
        strcat(mystring, "iel"); // concatenate to mystring

"iel" is a string literal (don't modify), but strcat() doesn't modify the second string
    
Can we concatenate strings with modifying any inputs? 

        char *newstring = newcat("Ar", "iel")

            char* newcat(const char *first, const char *second){
                char* cat_str;
                cat_str = malloc(strlen(first) + strlen(second) + 1);
            if(cat_str == NULL){
                return cat_str;
            }
            strcpy(cat_str, first);
            strcat(cat_str, second);
            return cat_str;
        } //don't forget to free

// --------------------- Streams ---------------------//
/* 
- Streams refer to sources of input or destinations for output
- Access streams using a file pointer (FILE *)

- Standard streams from stdio.h:
    - strout, stderr - outputs to screen
    - stdin - inputs from keyboard

- We can open files as streams to read from or write to

- Opening a file as a stream:

        FILE *fopen(const char *filename, const char *mode);
    
    -> filename: Use / or \\
    -> mode: "r", "w", "a" (append)
    -> Returns FILE* to use the file as a stream
    -> Returns null pointer if the file can't be opened

- Closing a file

        int fclose(FILE *stream);

    -> Returns 0 if successful, otherwise returns EOF as error code

- Writing in a file

        int printf(const char *format, ...);

    -> Writes a formatted string to stdout

        int fprintf(FILE *stream, const char *format, ...);

    -> Writes a formatted string to a file stream

- Reading 

        int scanf(const char *format, ...);

    -> Read a formatted string to stdin

        int fscanf(FILE *stream, const char *format, ...);

    -> Reads a formatted string to a file stream

    These functions returns number of characters written, number of items read (EOF error code)


- Output

        int fput(int c, FILE *stream);

    -> Write one char to a file stream, returns the written character

        int fputs(const char *s, FILE *stream);

    -> Write a string to a stream

- Input

        int fgetc(FILE *stream);

    -> Read and return one char from a file stream, returns non-negative number

        char *fgets(char *s, int n, FILE *stream);

    -> Read a streing until either a newline character or n-1 characters + '\0' from a file stream and store it in s

Errors and end-of file returns EOF (negative integer constant)


*/

//------------------ Linux Commands ---------------//
/*

cat filename.txt         List contents of filename.txt
cat -n filename.txt      List content with line numbers
cat file1.txt filename.txt         List contents of both files

cat > filename.txt       Create newfile.txt
cat file.txt > filename.txt 

less file.txt             List contents of file.txt and navigate through

less -N file.txt          List contents with line numbers
less +n file.txt          Lists line n (ie 435) of file.txt

less +/string file.txt    List line of file.txt containing string

cat file.txt file2.txt | less