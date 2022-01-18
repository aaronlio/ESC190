#include <stdio.h> //need this to use the printf () function
#include "lab1.h" //need this to link our Lab 1 



int main() {
    // Testing Part 1
    double test_p1 = split_bill(50.01 , 0.13 , 0.15 , 2);
    printf("The split will be: $ %.2f.\n", test_p1);
    // $32.50

    double test_p11 = split_bill (50, 0.0000000000000001, 0, 1);
    printf ( " The split will be : $%.2f.\n " , test_p11 );
    // $50.01
    
    
    double test_p12 = split_bill (36.78 , 0.13 , 0.15 , 5);
    printf ( " The split will be : $%.2f.\n " , test_p12 );
    // $9.56
    
    double test_p13 = split_bill (25.55 , 0.0 , 0.0 , 5);
    printf ( " The split will be : $%.2f.\n " , test_p13 );
    // 5.11

    // Testing Part 2
    double test_p2 = adjust_price (25.00);
    printf("The adjusted price is: $ %.2f.\n", test_p2 );
    // Should be $50 .00


    // Testing Part 3
    char test_food [] = "abcd ee";
    int test_p3 = sandy_eats ( test_food );
    if (test_p3 == 0){
    printf("Sandy would NOT eat '%s'.\n", test_food );
    }
    else {
    printf("Sandy would eat '%s'.\n", test_food );
    }
    // Sandy would eat ‘Three Cheese Pizza ’.

    // Testing Part 4
    char test_p4 [30] = "zebra";
    imagine_fish(test_p4);
    printf("Just imagine, a %s\n", test_p4);
    // Just imagine, a zebrafish !
    return 0;
}

/* 
The following line can be used to round values to the nearest integer:
    result = (int) (num + 0.5); 
*/

