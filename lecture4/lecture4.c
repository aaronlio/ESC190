//------------------------------ Lecture 4 ------------------------//

/* Functions declarations can be organized into header files instead of being put directly in a .c file

In your main AND in your functions file: 

#include "header.h"

// ------------------------ Strings and Post-Lecture 3 Discussion ------------------------//

/* 
char hello[10] = "hello";
    - h e l l o \0 \0 \0 \0 \0

char hello[10];
hello[0] = 'h';
hello[1] = 'i';
    - 2-9 are undefined

is "ad" > "abc"?
    - printf("%d\n", strcmp("ad", "abc")); //yes, 'd' > 'b'

Can we use strlen() on char array
    - Yes- counts characters up until '\0' (\0 not included)

String Literal:
    - char* example = "hello";
        - example[1] = 'o'; --> PROGRAM WILL CRASH, DON'T DO THIS
    
    - This string is stored in a section of memory that can't be modified

From previous lecture:
    - if(tmp-48 == 5) to check for '5' in the string
    - Can also try:
        - if(tmp-'0' == 5), if(tmp == '5'), if(tmp == 53)

*/

//------------------------ Sorting Algorithms ------------------------//
/* 

- An algorithm is a step-by-step procedure to accomplish a task
    - In Python:
        - list.sort() --> over 3000+ lines of C code!

- We can compare algorithms by their runtime
    - We identify the best/average/worst case scenarios
    - Usually focus on the worst case (upper bound)

*/


// ------------------------------ Complexity Notation ------------------------ //
/*

- Big O notation defines an upper bound for the runtime complexity
    - Omega notation defines lower bound
    - Theta notation defines upper and lower bounds

- We can about the time but we can't compute this so we consider units proportional to runtime (number of iterations, operations)
    - Write as a function of the size of the input n.

- We care about what happens when the input is large
    - Drop slow-growing (smaller) terms and constant coefficients

- f(n) is O(g(n)) if f(n) grows at most as fast as g(n) for large n
    - As n --> ∞, g(n)/f(n) < ∞ (for large n)
    - Ex, 5n^2 + n + 2 is O(n^2)
        - We could also technically say O(n^5) but we want to give a tight upper bound

- Summing elements of an array, arr[n]:

    int sum = 0; // O(1)
    for (int i = 0; i <= n; i++) // O(i)
    {
        statements 
    } 

    - O(1) -> O(log(n)) -> O(n) -> O(n(log(n))) -> O(n^2) --> O(n!)

*/

// ------------------------------ Insertion sort ------------------------//
/*

Iterate through elements in the unsorted section, taking one element at a time and inserting 
it into the correct position of the sorted side of the array.

2, 5, 1, 4, 3
2       5, 1, 4, 3
2, 5    1, 4, 3
1,2,5   4, 3
1,2,4,5     3
1,2,3,4,5

Best case = O(n):
    - Array is already sorted
    - n-1 comparisons -> O(n)
    - No swaps -> O(0)

Worst case = O(n^2):
    - Array is sorted in reverse
    - 1+2+3+...(n-1) =          (n^2 + n)/2  comparisons --> O(n2)
    1+2+3+...(n-1) =            (n^2 + n)/2 swaps  --> O(n^2)

*/
// ------------------------------ Selection sort ------------------------//
/*

Iterate through array elements in the unsorted section, find the smallest and moving it ot the front of the unsorted section
2, 5, 1, 4, 3
1       2, 5, 4, 3
1, 2    5, 4, 3
1,2,3   5, 4
1,2,3,4     5
1,2,3,4,5

Best case: O(n^2)
    - sorted already
    - (n-1) + (n-2) + ... 2+1 comparisons --> O(n^2)
    - No swaps --> O(0)

Worst case = O(n^2)
    - Array is reversed
    - (n-1) + (n-2) + ... 2+1 comparisons --> O(n^2)
    -  (n-1) + (n-2) + ... 2+1 swaps --> O(n^2)

*/

// ------------------------------ Bubble sort ------------------------//
/*
Iterate through unsorted section, moving largest element of unsorted to the sorted section

2, 5, 1, 4, 3 --> 5 moves down, is now sorted

2,1,4,3     5 
1,2,3       4, 5 
1,2,        3, 4, 5 
1,2,3,4,5

Best case = O(n):
    - Sorted
    - No swaps
    - if we count the number of swaps per sweepl we can stop if 0 swaps were made
        - ie. after n-1 comparisons -> O(n-1 + 0) -> O(n)
    - without early termination, we would do (n-1) + ...2 + 1 = O(n^2)

Worst Case = O(n^2):
    - In reverse
    - (n-1) + (n-2) + ... 2+1 comparisons --> O(n^2)
    -  (n-1) + (n-2) + ... 2+1 swaps --> O(n^2)
*/
// ------------------------------ Merge sort ------------------------//
/* 

Divide and conquer: Split the array in halves repeatedly to form single
element (sorted) arrays and merge the subarrays to form one single sorted array.

3, 6, 5, 1, 4, 2
    |          |
3, 6, 5     1, 4, 2
   |   |    |      |
3, 6   5   1,4      2

3   6   5   1   4   2
   |    |     |     |
3, 6    5   1,4     2
  |   /       |  /
3,5,6       1,2,4

1,2,3,4,5,6


When we merge two array, each with m elements, we have roughly O(2m) -> O(m)
    - At each level, we merge n/k elements, k times -> each O(n).

Total merging complexity = number of levels * n
    - There are log2 n elements

If we disregard the single element merges
    - Then we can say the number of levels is log2n

Splitting complexity O(1) * n-1 elements -> O(n-1) -> O(n)

Merging complexity -> O(nlogn)
O(nlogn) grows faster than O(n)

Best/Worst case of merge sort is O(nlogn)*/