//------------------------ Lecture 7 ------------------------//
/* Try installing Valgrind on mac, or ssh into ecf*/

/* Allocate new memory

        void *malloc(size_t size);
        void *calloc(size_t nmemb, size_t size);


        int n = 5;
        int *ptr_a = malloc(n * sizeof(int)); --> like array[5];
        int *ptr_b = calloc(n, sizeof(int)); --> like array[5] = {0} (all elements set to 0)

        int *another = ptr_b;
        ....
        free(ptr_a);
        free(another); //same block as ptr_b, don't clear both

*/

/*

- How to dynamically change array size:

        int n = 4;
        int *ptr_b = callc(n, sizeof(int));
        int *another = ptr_b;
        int *ptr_b = realloc(ptr_b, 2*sizeof(int));
        another = ptr_b;
        int *ptr_b = realloc(ptr_b, 6*sizeof(int));
        another = ptr_b;
        ...
        free(ptr_b)

*/

/* Another example

        int **x = (int**)malloc(sizeof(int*) * 5);
        for (int i = 0; i<5;i++){
            *(x+i) = (int *) calloc(2,sizeof(int))
        }

    This creates 5 arrays at *(x+0), *(x+1), ... *(x+4) that contain two elements each

    6 free()s are needed, 
    free(*(x+i));
    free(x)

*/

/* Passing double pointers to functions

        void change_array_size(int* ptr){
            ptr = realloc(ptr, sizeof(int) * 4);
        } //ptr is lost when the function ends

        int main(){
            int* ptr= (int *)malloc(sizeof(int) * 2);
            change_array_size(ptr);
            return 0;
        }

    To fix the memory leak above:

        void change_array_size(int** ptr){
            *ptr = realloc(*ptr, sizeof(int) * 4);
        } // realloc() frees when re-locating

        int main(){
            int* ptr= (int *)malloc(sizeof(int) * 2);
            change_array_size(&ptr);
            return 0;
        }

        */
// ------------------------ STRUCTS ------------------------//

//Structure Variables

/* Structures allow us to group variables as a new data type

To declare a structure:

        struct pricetag{
            double price;
            double sale_price;
            char item_name[100];
        };

        struct pricetag new_item = {10.99, 4.99, "Shelf"};

        -------- OR --------

        typedef struct{
            double price;
            double sale_price;
            char item_name[100]
        } pricetag; --> don't forget semicolon

        pricetag new_item = {10.99, 4.99, "Shelf"};

        --------- OR ---------
        
        struct pricetag new_item;
        new_item.sale_price = .25;
        printf("%.2f", new_item.sale_price);

When you pass a struct to a function, it makes a copy. 
It is more efficient to pass a pointer to a structure variable

        struct pricetag *ptag_ptr;
        ptag_ptr = mallow(sizeof(struct pricetag));

        (*ptag_ptr).sale_price = .25;
        printf("Sale price is %.2f", (*ptag_ptr).sale_price)

        --------- OR ---------
        ptag_ptr->sale_price=.15;
        printf(".2f", ptag_ptr->sale_price)

*/