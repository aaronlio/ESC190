/*----------------------------------------- Lab 0 - Submission -------------------------------------*/
// ------------------------ 3456 in base 2 ---------------------- //

/*
(1 * 2^11) + (1 * 2^10) + (1 * 2^8) + (1 * 2^7) = 110110000000 = 3456⌄10
*/

/* Each digit in our binary representation is called a “bit”. The least-significant bit (LSB) is the digit
that is the co-efficient of 2^0, and the most-significant bit (MSB) is the digit that is the co-efficient
of the highest power of 2 needed to represent the value. Alternative names for the LSB and MSB
are right-most bit and left-most bit, respectively. */

// ------------------------ Data ---------------------- //
/* The previous section established that all computer data is stored in bits. This naturally lends itself
well to numeric data, as we previously saw. What about other types of data? For text data, there
are encoding standards such as ASCII and UTF-8 that are used for representing text as numbers
in computer systems.3 A computer operating system is then just a highly structured interface for
reading and writing bits. Every computer program is asking to save bits when saving files and read
bits when reading files. With billions of bits flying around, with the order of the bits of utmost
importance, it is important for the computer’s operating system (OS) to keep track of things in an
orderly fashion. The orderly fashion imposed by the OS is a file system. The components of a file
system are directories and files. Directories contain other directories and files. Files are ordered
sequences of bits that store data. */

/* Note: there are parent --> child directories, the child of a child is a descendent of the parent, and a parent is an
ancestor of the child of a child. */

/* The root directory is an ancestor of all other directories (think Adam and Eve without Eve) 
A relative path is the path from a specific (current) directory ./Lab0.c, whereas the absolute is the path from 
the root /Users/aaron/Documents/ESC190/Lab0.c.

In other words, Root directory is the base of the file tree, everything else, including the OS system files, is in it. 
Home directory is within the root directory, and contains user files, contained in a sub directory for each user.
*/

//Screen Shot 2022-01-10 at 10.03.50 PM.png


// ------------------------ Linux Commands ---------------------- //
/* cd ~ means changing directories relative to the home directory 
ie. cd Users/aaron/Documents/ESC190 is the same as cd ~/Documents/ESC190
if no path is entered, both cd and cd ~ will take you back to the home directory 

.  = current directory
.. = parent directory
~  = home directory
/  = root directory
*/


/*----------- EXAMPLE of directory selection and creation---------/

    > cd Documents
    > mkdir some_dir # create a new directory called some_dir
    > ls # you should see some_dir created
    > mkdir ./ another_dir
    > ls # you should see some_dir and another_dir
    > cd some_dir # change directory to be in some_dir
    > pwd # you should see that you are now in some_dir
    > mkdir ../ third_dir
    > mkdir ../ third_dir/inside_dir
    > ls
    > ls .
    > ls ..
    > ls ../ third_dir
    > pwd # you should see you have not moved out of some_dir

1) The relative path of some_dir (WRT Documents), is simply ./some_dir, 
and it's absolute path is Users/aaron/Documents/some_dir

2) When using the ls command without a path, it lists the files and sub-directories
in the current directory

3) 
Documents
    |
    ------- some_dir
    |
    ------- another_dir
    |
    ------- third_dir 
                |
                ------- inside_dir


4) There is no different between ls and ls ., they will both list directories for some_dir (current directory)
5) l .. lists directories in Documents (parent directory)
6) pwd (print working directory), simply prints your current directory, it doesn't change it

If we're looking to create a file inside third_dir and compile a file inside third_dir, we can use the following:

        cd ../third_dir
        touch main.c
        nano main.c #vim main.c is preferred
        -- Enter code, save and quit (using :wq on Vim or ^X on nano) --
        gcc main.c -o main
        ./main 

if we ran:

        cd ..

to run the file, run:

        ./third_dir/main
    
*/