//------------------------------------ Lecture 5 ------------------------------//
//------------ More on complexity ------------------//

/* 

In Merge Sort, we were merging two arrays of similar length
    - O(2m) -> O(m)

If the arrays were different lengths 
    - We would have O(a + b) where a and b are the lenghts

What is the runtime complexity of comparing two strings
    - Best: first character is diff O(1)
    - Worst: Last is different, O(min(a,b))

*/

// Keys: Always define your variables

//------------------ Quick Sort (smallest to largest) ------------------//
/*

Divide and conquer: Set an element to be the pivot.
Move elements smaller than the pivot to the left of the pivot and move greater elements to the right. 
Pivot element will be sorted. Repeat on the left and right section

7 3 6 2 8 1 5 (4 - pivot)
1 3 2 4 8 7 5 6 - move elements based on size relative to pivot (4)
1 3 (2 - pivot) 4 8 7 5 (6 - pivot)
(1 - pivot) 2 (3 - pivot) 4 (5 - pivot) 6 8 (7 - pivot)
1 2 3 4 5 6 7 (8 - pivot)
1 2 3 4 5 6 7 8

There are many ways to shuffle elements, here is one way you can do it:
    - Set last element (ie. 4), as the pivot
    - Left index (7), finds elements > 4, Right index (5), finds elements < 4, the first of which is 1:
        - When the both find one, they swap the numbers at their indexes
    - Indexes move in
    - Once the indexes corss over, the pivot is swapped with the Left Index, which is now to the right of the Right Index

Backwards example: https://runestone.academy/ns/books/published//pythonds/_images/partitionA.png


------------ Complexity ------------
Best case:
    - O(nlog(n))
    - Top level --> n elements to handle once
    - 2nd level --> n/2 elem to handle twice, etcetc
    - then n/i handled i times
    - O(n) at each level over log2(n) levels
    - Therefore O(nlog(n))

Worst case:
    - O(n^2)
    - The pivot is always the smallest or largest element, so the subsequent partitions are unbalanced the entire time
    - n + (n-1) + ..2 + 1 comparisons/swaps across all partitions
    - O(n^2)


--------- NOTES about QS ---------
- Choice of pivot element
    - In our examples, the last element was taken as the pivot
    - Useful for suffling elements
    - Results in worst-case when the array is sorted

- Alternatives:
    - First element
    - Middle element, random element
    - Median of small set of elements
    - etc, etc
*/

//--------------- OVERVIEW OF SORTING ALGS ---------------//
/*

Insertion sort --- O(n) --- O(n^2)
Selection --- O(n^2) O(n^2)
Bubble 
Merge O(nlog(n))
Quick O(nlog(n))


Worst Case: Merge is fastest
    - Quick can suually avoid the worst case
    - Quick sort has better space complexity

Best case: Intertion and bubble are fastest
    - Rarely expect the data to be naturally sorted already
    - Should probably use either Merge or Quick unless small dataset

Comparison sorts are limited to O(n) for best cases and O(nlogn) for worst cases
    - (see Radix Sorts, which takes advantage of other operations)
    - Python list.sort() uses Tim Sort, a hybrid of Merge/Insertion Sort

*/