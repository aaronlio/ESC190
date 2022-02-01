//---------------------------- Lecture 9 ----------------------------//
// -------------- Data Structures --------------//
/* 

A data structure is a way to organize and access data
    - Design involves designing abstract data types

Recall static arrays - lots of room for improvement
    - More than one data type?
    - More than one value?
    - Rearrage data?
    - More/fewer elements
*/

// -------------- Linked List -------------- //
/*

Chain of structs, each struct is called a node.
    - Each node contains a pointer to the next node in thh chain
    - We have a head pointer pointing to the first node
    - Usually the last node points to NULL

        if(node_ptr->next == NULL) //*node is the last node
        if(node_ptr->next->next == NULL) //*node is the second last node

    - head - node struct pointer (node *, struct node *) //first node
    - head->next is the seond node //also (*head).next

To get the ith node i: O(i) complexity

To insert at ith node: O(i)
    - Use a double pointer

To insert in the middle:
    - New node -> next to existing node to go after
    - last node from front segment -> next to new node

To delete a node:
    - Use a temp pointer to node to be deleted
    - head->next to node after deleted node
    - free(temp)
*/

#include <stdlib.h>

void change_array_size(int* ptr){
    ptr = realloc(ptr, sizeof(int)*4);
}//ptr is lost when the function ends

/*NOTE: realloc() frees the original block if it needs to move, so *ptr will be free here*/

int main(){
    int* ptr = (int *)malloc(sizeof(int)*2);
    change_array_size(ptr);
    return 0;
}//missing free for malloc

/* If there's not enough space to realloc in place, it will free the original memory space, meaning the pointer
to the original list block will be lost.*/

        