#include "lab3.h"
#include <stdlib.h>
#include <string.h>
//Add TA party item request to the list
int add_request(struct party_node **head, char *item, double price, char *ta){
    if (strcmp(item, "IDE") == 0){
        return -1;
    }
    struct party_node *new_node = (struct party_node *)malloc(sizeof(struct party_node));
    new_node->item = (char*)malloc(sizeof(char)*strlen(item)+1);
    new_node->ta = (char*)malloc(sizeof(char)*strlen(ta)+1);
    strcpy(new_node->item, item);
    strcpy(new_node->ta, ta);
    new_node->price = price;
    
    new_node->next = *head;
    *head = new_node;
    
    return 0;

}

//Remove the last item added
void remove_request(struct party_node **head){
    if (*head == NULL){
        printf("Could not remove request!");
    }
    struct party_node *temp = *head;
    *head = temp->next;
    free(temp->item);
    free(temp->ta);
    free(temp);
}

//Sort party item requests - in place?
void make_sorted(struct party_node **head){
    int swap_flag = 1;
    struct party_node *curr = *head;
    struct party_node *last_index_to_check = NULL;

    if (*head == NULL){
        return;
        }

    while (swap_flag){
        swap_flag = 0;
        curr = *head;

        while(curr->next != last_index_to_check){
            if(curr->next->price > curr->price){
                float temp_price = curr->next->price;
                char *temp_ta = curr->next->ta;
                char *temp_item = curr->next->item;

                curr->next->price = curr->price;
                curr->next->ta = curr->ta;
                curr->next->item = curr->item;

                curr->price = temp_price;
                curr->ta = temp_ta;
                curr->item = temp_item;

                swap_flag = 1;
            }
            curr = curr->next;
        }
        last_index_to_check = curr;
 
    }
}

//Trim list to fit the budget
double finalize_list(struct party_node **head, double budget){
    struct party_node *curr = *head;
    struct party_node *prev = NULL;
    while(curr != NULL){
        if(curr->price > budget){
            if(curr == *head){
                curr = curr->next;
                remove_request(head);
            }
            else{
                prev->next = curr->next;
                free(curr->item);
                free(curr->ta); 
                free(curr);
                curr = prev->next;
            }
            
        }
        else{
            budget -= curr->price;
            prev = curr;
            curr = curr->next;
        }
    }
    free(curr);
    return budget;
}

//Print the current list - hope this is helpful!
void print_list(struct party_node *head){
    int count = 1;
    printf("The current list contains:\n");
    while(head!=NULL){
        printf("Item %d: %s, %.2lf, requested by %s\n",
            count, head->item, head->price, head->ta);
        count++;
        head = head->next;
    }
    printf("\n\n");
    return;
}

 