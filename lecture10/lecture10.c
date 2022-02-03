//------------------------ Lecture 10 ------------------------//
#include <stdlib.h>
#include <stdio.h>
struct node{
    int data; //data in ode
    struct node *next; //points to next node
};

struct node* insert_node(struct node *head, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return head;
}

int search_list(struct node *head, int value){
    while (head!=NULL){
        if (head->data == value){
            return 1; //found it!
        }
        head = head->next;
    }
    return 0;
}

struct node* delete_node(struct node *head, int value){
    struct node *curr=head, *prev=NULL;
    while(curr!=NULL && curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        return head;
    }
    else if(prev==NULL){
        head = head->next;
    }
    else
        prev->next = curr->next;
    
    free(curr);
    return head;
}

void print_list(struct node *head){
    printf("\nThe data in this list is: ");
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

void delete_list(struct node **head){
    struct node *curr=*head, *prev=curr;

    while(curr->next!=NULL){
        curr = curr->next;
        free(prev);
        prev = curr;
    }
    free(curr);
    *head = NULL;
    return;
}

int main(){
    struct node *head = NULL;
    head = insert_node(head,4); //insert
    head = insert_node(head,3); //insert
    head = insert_node(head,2); //insert
    head = insert_node(head,1); //insert

    int found = 0;
    found = search_list(head,2);
    if (found){
        printf("2 is in the list");
    }

    print_list(head);
    
    
    //more code

    // To insert a node, make the new node point to somewhere in the list, make the previous node point to the new node
    
    /*Traversing the list to search for a value, return value, return point to node, operations on nodes
    Use a pointer to loop through the list until value is found or until we get to the end */

    /*To delete, locate the node in front of to-be-deleted, hold onto the address of the TBD
    Connect previous node to node after TBD, free the node TBD
    */
    return 0;

};

/*
If a function can modify the first node, but is only passed a pointer to the first node, you should:
    - return a pointer to the new first node
    - Update the pointer to the first node in the calling function

- Working with a double pointer to the first node allows you to modify the head pointer.
- We can then return other useful data (ie. confirmation of insertion/deletion, etc)