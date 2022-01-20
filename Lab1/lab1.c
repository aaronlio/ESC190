#include <math.h>
#include <string.h>
#include <stdio.h>
#include "lab1.h"

double split_bill(double base_amount, double tax_rate, double tip_rate, int num_people) {
    //
    double split = ((base_amount*(1+tax_rate))*(1+tip_rate)/num_people);

    if (split- ((int) (split*100) / 100.0) < .0000001){
        return split;
    }
    return (ceil(split * 100))/100;
}

double adjust_price(double original_price) {
    return 10*(pow(original_price, .5));
}

int sandy_eats(char menu_item[]){
    /*if (strstr(menu_item, "I") != NULL || strstr(menu_item, "i") != NULL ||  \
    strstr(menu_item, "J") != NULL || strstr(menu_item, "j") != NULL ||  \
    strstr(menu_item, "k") != NULL || strstr(menu_item, "K") != NULL  || \
    strstr(menu_item, "fish") != NULL || strstr(menu_item, "Fish") != NULL) {
        return 0;
    } */
    int i = 0;
    char illegal[10][10] = {"J", "K", "L", "l", "k", "l", "fish", "Fish"};
    while (menu_item[i] != '\0'){
        if (strstr(menu_item, illegal[i]) != NULL){
            return 0;
        }
        i++;  
    }
    int length = 0;
    int max_length = strlen(menu_item);
    for (int i = 0; i < max_length; i++){
        if (menu_item[i] != ' '){
            length ++;
        }
    }
    // Rather than removing spaces, could have simply counted letters using ASCII codes or char array
    
    if (length % 2 == 1) return 0;
    return 1;
}

void imagine_fish(char thing[]){
    //strcat(thing, "fish");
    int str_len = strlen(thing);
    char word[] = "fish";
    for (int i = 0; i < 5; i++){
        thing[str_len + i] = word[i];
    }
}