#include <stdio.h>
#include "lab3.h"

int main(){
    //Empty list
    struct party_node *head = NULL;

    int check_add = 0;
    //Adding TA requests
    printf("Adding the TA requests:\n");
    check_add = add_request(&head, "Speakers", 99.99, "Zoe");
    check_add = add_request(&head, "Sushi", 288.88, "Ali");
    //Check add_request() return value
    check_add = add_request(&head, "Board games", 150.00, "Bill");
    if(check_add==-1){
        printf("Board games was not added.\n");
    }
    check_add = add_request(&head, "IDE", 0.00, "TA who will not be named");
    if(check_add==-1){
        printf("IDE was not added.\n");
    }
    check_add = add_request(&head, "Balloons", 2.49, "Brian");
    check_add = add_request(&head, "Limousine rental", 500.01, "Tony");
    check_add = add_request(&head, "Coffee and doughnuts", 10.00, "Nhien");
    check_add = add_request(&head, "Croissants", 2.50, "Gil");
    check_add = add_request(&head, "Pineapple pizza", 9.99, "Jeffrey");
    check_add = add_request(&head, "Charcuterie tray", 9.50, "Samantha");
    check_add = add_request(&head, "Champagne", 100.00, "Samantha");

    print_list(head); //10 requests added

    //Remove Samantha's request for Champagne
    printf("LIFO removal:\n");
    remove_request(&head);
    print_list(head);

    //Sort by price
    printf("Sorting by price:\n");
    make_sorted(&head);
    print_list(head);

    //Finalize the shopping list
    printf("Finalizing the shopping list:\n");
    double remainder=0.00;
    remainder = finalize_list(&head, 500.00);
    print_list(head);
    printf("The remainder after shopping is: %.2lf\n", remainder);

    //Free the list
    while(head!=NULL){
        remove_request(&head);
    }
    printf("Ready to party!\n");
    return 0; 
}