//------------------------------ lecture 11 ----------------------------//
#include <stdlib.h>
#include <stdio.h>
struct node{
    int data; //data in ode
    struct node *next; //points to next node
};

void insert_node(struct node **head, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
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

int delete_node(struct node **head, int value){
    struct node *curr=*head, *prev=NULL;
    while(curr!=NULL && curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        return -1;
    }
    else if(prev==NULL){
        *head = (*head)->next;
    }
    else
        prev->next = curr->next;
    
    int saved_value = curr->data;
    free(curr);
    return saved_value;
}
int main(){
    struct node *head = NULL;
    insert_node(&head,4); //insert
    insert_node(&head,3); //insert
    insert_node(&head,2); //insert
    insert_node(&head,1); //insert
    int deleted;
    deleted = delete_node(&head,1);
    print_list(head);
    int found = 0;
    found = search_list(head,2);
    if (found){
        printf("2 is in the list");
    return 0;
    }

    // You can insert recursively by doing insert_node(head->next,val), this passes a linked list that is 1 node smaller.

/* Indexing

        head = head->next; //same as head = (*head).next;

Each time this runs, the temp head pointer moves through the linked lists*/