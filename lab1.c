#include <math.h>
#include <string.h>

double split_bill(double base_amount, double tax_rate, double tip_rate, int num_people) {
    double split = ((base_amount*(1+tax_rate))*(1+tip_rate)/num_people);
    return ceil(split*100)/100;
}

double adjust_price(double original_price) {
    return 10*(pow(original_price, .5));
}

int sandy_eats(char menu_item []){
    if (strstr(menu_item, "I") != NULL || strstr(menu_item, "J") != NULL || strstr(menu_item, "K") != NULL || strstr(menu_item, "fish") != NULL || strstr(menu_item, "Fish") != NULL) {
        return 0;
    } 
    if (strlen(menu_item) % 2 != 0){
        return 0;
    }
    return 1;
}

void imagine_fish(char thing []){
    strcat(thing, "fish");
}