#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct a_stack{
    char *arr;
    int num_items;
    int size;
};

void push(struct a_stack *mystack, char value);
char pop(struct a_stack *mystack);
char peek(struct a_stack *mystack);
void resize(struct a_stack *mystack);


void push(struct a_stack *mystack, char value){
    //Check if stack is full
    if(mystack->num_items == mystack->size){
        resize(mystack);
    }

    //Push item to stack and update num_items
    (mystack->arr)[mystack->num_items] = value;
    (mystack->num_items)++;

    return;

}

char pop(struct a_stack *mystack){
    //Check if stack is empty
    if(mystack->num_items == 0){
        printf("no pop!\n");
        return '\0';
    }

    //Save data to return, then designate
    char pop_val = mystack->arr[(mystack->num_items)-1];
    (mystack->arr)[(mystack->num_items-1)] = '0'; //optional
    return pop_val;
}
char peek(struct a_stack *mystack){
    if(mystack->num_items == 0){
        printf("stack empty!");
    }
    return (mystack->arr[mystack->num_items]);
}

int main(){
    struct a_stack *mystack 
}