#include <stdio.h>
#include <stdlib.h>
#define GRID_SIZE 10
void print_stat_grid(char grid[GRID_SIZE][GRID_SIZE], int n);
void print_dyn_grid(char **grid_ptr, int n);
void free_grid(char **grid_ptr);
int main() {
    
    //Static 2D array
char static_arr[GRID_SIZE][GRID_SIZE];    
    // Fill diagonal with '1's, rest with '0's
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            if(i==j){
                static_arr[i][j] = '1';
            }
            else{
                static_arr[i][j] = '0';
            }
        }
    }
    print_stat_grid(static_arr, GRID_SIZE);
    printf("\n");
    
    
    //Dynamic 2D array
    char **dyn_arr = malloc(GRID_SIZE*sizeof(char *));  // allocate for the rows
    char **current_ptr;         // helper pointer
    
    //Filling in the grid
    for(int i=0; i<GRID_SIZE; i++){                     // iterate rows
        current_ptr = dyn_arr+i;                        // point to a row
        *current_ptr = malloc(GRID_SIZE*sizeof(char));  // allocate for the columns of the row
        for(int j=0; j<GRID_SIZE; j++){                 // iterate columns
            if(i==j){
                (*current_ptr)[j] = '1';
            }
            else{
                (*current_ptr)[j] = '0';
            }
        }
    }
    print_dyn_grid(dyn_arr, GRID_SIZE);
    free_grid(dyn_arr);
    
return 0;
}
void print_stat_grid(char grid[GRID_SIZE][GRID_SIZE], int n){    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n"); // end of row
    }
    return;
}
void print_dyn_grid(char **grid_ptr, int n){    
    char *element_ptr;      // helper pointer
    for(int i=0; i<n; i++){
        element_ptr = *(grid_ptr+i);            // point first element of a row
        for(int j=0; j<n; j++){
            printf("%c ", *(element_ptr+j));    // access column element
        }
        printf("\n");                           // end of row
    }
    return;
}
void free_grid(char **grid_ptr){
    for(int i=0; i<GRID_SIZE; i++){
        free(*(grid_ptr+i));            // free each column
    }
    free(grid_ptr);                    // free the rows
    return;