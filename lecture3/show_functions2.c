#include <stdio.h>
#define ARR_LENGTH 5 // ARR_LENGTH will be replaced with 5

int multiply(int x[]){
    int result = x[0]*x[1];
    return result;

}

void doubler(int x[]){
    for (int i=0; i<ARR_LENGTH; i++){
        x[i] *= 2;
    }
}

int main(){
    int x[] = {2,3};
    int y[ARR_LENGTH] = {5,5,5,5,5};
    {

    }
}