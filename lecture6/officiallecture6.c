#include <stdio.h> 
//int no_change(int a); 
void no_change(int a); 
void yes_change(int *a); 
int main(){ 
   // Variable declarations 
   int x = 5, *y = &x, **z = &y; 
   //Printing memory addresses 
   printf("The memory address of x is: %p\n", &x); 
   printf("The memory address of x is: %p\n\n", y); 
   printf("The memory address of y is: %p\n", &y); 
   printf("The memory address of y is: %p\n\n", z); 
 
   // These should all print 5 
   printf("The value stored at &x is: %d\n", x); 
   printf("The value stored at &x is: %d\n", *y); 
   printf("The value stored at &x is: %d\n", **z); 
   // This works toot need to use & 
   // similar to int *array_ptr = &my_array[0]; 
   printf("Value of *array_ptr is %d\n\n", *array_ptr); 
    
    
   // Pointer arithmetic 
   array_ptr = array_ptr + 2;  // array_ptr = &my_array[2] 
   printf("Value of *array_ptr is %d\n", *array_ptr); 
   array_ptr = array_ptr - 1;  // array_ptr = &my_array[1] 
   printf("Value of *array_ptr is %d\n", *array_ptr); 
   *(my_array+3) = 5;              // my_array[3] = 5; 
   printf("Value of my_array[3] is %d\n", my_array[3]); 
   *(array_ptr+2) = 6;         // my_array[3] = 6; 
   printf("Value of my_array[3] is %d\n\n", my_array[3]); 
    
    
   //int *a_ptr = my_array; //need this to use printf("%d\n", 
    *(a_ptr+i)); 
   for(int i=0; i<5; i++){ 
       printf("%d\n", my_array[i]); 
       //printf("%d\n", *(my_array+i)); 
       //printf("%d\n", *(a_ptr+i)); 
   } 
   printf("\n"); 
    
    
   int *another, ptr_sub; 
   array_ptr = my_array + 3;       // array_ptr = &my_array[3];  
   another = array_ptr - 2;        // another = &my_array[1]; 
   ptr_sub = array_ptr - another;  // ptr_sub = 2 
   printf("Value of ptr_sub is %d\n", ptr_sub); 
    
   return 0; 
} 
//int no_change(int a){ 
void no_change(int a){ //copies an integer value into a 
   a = 2; 
   //return a; 
} 
void yes_change(int *a){ //copies a memory address into a 
   *a = 2; 
} 