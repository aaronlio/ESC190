#include <string.h>
#include <stdio.h>

void func1(char s[]){
    int i = 0;
    char letter = s[i];
    for (;s[i] != '\0'; i++){
        printf("%c", s[i]);
    }

}

void func2(char s[]){
    NULL;
}

int main(){
    char s[] = "Three Cheese Pizza";
    char p[] = "Three Chee5e Pi55a";
    char c = 'a';
    c = 2 * c - 1;
    printf("%d", c);
}