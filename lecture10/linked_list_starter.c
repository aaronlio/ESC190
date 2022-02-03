#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int cargo;
	struct ListNode* next; // Q for the class: why not just an actual ListNode?
} ListNode;

void print_ll(ListNode* head){

}

ListNode* create_ll(int* arr, int n){
	/**
		arr is an arry representing the sequence of elements
		to construct a list from; it has n elements
	*/
	
}

void insert(ListNode* head, int idx, int val){
}


void delete_ll(ListNode** head){
}


void main(){
	int arr[] = {1, 7, 100, 20};
	int n = 4;
	ListNode* head = create_ll(arr, n);
	print_ll(head);
	
	int val = 35;
	int i = 3;
	fprintf(stdout, "Now inserting value %d at index %d...\n", val, i);
	insert(head, i, val);
	print_ll(head);
	
	val = 2000;
	i = 5;
	
	fprintf(stdout, "Now inserting value %d at index %d...\n", val, i);
	insert(head, i, val);
	print_ll(head);
	
	delete_ll(&head);
}