#include <stdio.h>
#define FNAME "greetings.txt"
// Note: make your own greetings.txt file first

int main(){
    
    char name[30];
    
    printf("Hello! What is your name?\n");
    scanf("%s", name);
    
    //Separating the printed string for style (avoiding long line of code)
    printf("Welcome, %s. Let me tell you what's here!\n\n"
            "We currently have: \n", name);
    
    //Open file for reading
    FILE *fp = fopen(FNAME, "r");
    if(fp==NULL){
        fprintf(stderr, "Could not open the file!\n");
        return 0;
    }
    
    char line[30];
    //Read and print a line from greetings.txt
    while(fgets(line, 30, fp) != NULL){
        printf("%s", line);
    }
    fclose(fp); //Done reading from the file
    

    printf("\nWould you like to add to the collection? [y/n] ");
    char answer = 'n';
    scanf(" %c", &answer); //Add a space to skip whitespace
    
    if(answer=='y'){

        char item[30];
        printf("What are you adding? ");
        scanf("%s", item);
        
        //Open file for appending
        FILE *fp = fopen(FNAME, "a");
        if(fp==NULL){
            return 0;
        }
        fputs(item, fp);
        fputc('\n', fp);
        fclose(fp); //Done appending to the file
        
        printf("Thank you for your contribution!\n");
    }
    
    printf("Okay, bye!\n");
   
    return 0;
}