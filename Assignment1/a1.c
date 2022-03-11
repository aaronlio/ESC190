#include "a1.h"


/**
	Add your functions to this file.
	Make sure to review a1.h.
	Do NOT include a main() function in this file
	when you submit.
*/
Restaurant* initialize_restaurant(char* name){
	Restaurant* restaurant = (Restaurant*)malloc(sizeof(Restaurant));

	restaurant->name = malloc(sizeof(char)*strlen(name)+1);
	strcpy(restaurant->name, name);

	restaurant->menu = load_menu(MENU_FNAME);

	restaurant->num_completed_orders = 0;
	restaurant->num_pending_orders = 0;
	
	restaurant->pending_orders = (Queue*)malloc(sizeof(Queue));
	restaurant->pending_orders->head = NULL;
	restaurant->pending_orders->tail = NULL;

	return restaurant;
} 
Menu* load_menu(char* fname){
	FILE *fp = fopen(fname, "r");
	int num_items = 0;
	char line[255];
	while(fgets(line, 255, fp) != NULL){
		if(strtok(line, MENU_DELIM) != NULL){
				num_items++;
			}
		}
	fseek(fp, 0, SEEK_SET);
	Menu* menu = (Menu*)malloc(sizeof(Menu)); 
	menu->item_names = (char**)malloc(sizeof(char*)*num_items);
	menu->item_codes = (char**)malloc(sizeof(char*)*num_items);
	menu->item_cost_per_unit = (double*)malloc(sizeof(double)*num_items);
	menu->num_items = num_items;

	for (int k = 0; k < num_items; k++){
		menu->item_names[k] = (char*)malloc(MAX_ITEM_NAME_LENGTH * sizeof(char));
		menu->item_codes[k] = (char*)malloc(ITEM_CODE_LENGTH * sizeof(char));
	}
	char line2[255];

	int i = 0;

	while(fgets(line2, sizeof(line2), fp)!= NULL){
		strcpy(menu->item_codes[i], strtok(line2, MENU_DELIM));
		strcpy(menu->item_names[i], strtok(NULL, MENU_DELIM));
		char* price = strtok(NULL, MENU_DELIM);
		menu->item_cost_per_unit[i] = strtod(price+1, NULL);
		i++;
	}
	fclose(fp);
	return menu;
}
Order* build_order(char* items, char* quantities){
	// Init
	Order* new_order = (Order*)malloc(sizeof(Order));
	int num_items = strlen(items)/(ITEM_CODE_LENGTH-1);
	new_order->num_items = num_items;

	new_order->item_codes = (char **)calloc(num_items, sizeof(char *));
	for (int i = 0; i < num_items; i++){
		//new_order->item_codes[i] = (char *)malloc(ITEM_CODE_LENGTH * sizeof(char)); // NO NEED TO ALLOCATE SINCE strndup DOES IT FOR YOU.
	}
	new_order->item_quantities = (int *)calloc(num_items, sizeof(int));

	// Set quantities
	char *temp = (char *)malloc(sizeof(char)*strlen(quantities)+1);
	strcpy(temp, quantities);
	char* token = strtok(temp, MENU_DELIM);
	for (int i = 0; i < num_items; i++){
		new_order->item_codes[i] = strndup(items + (ITEM_CODE_LENGTH-1)*i, 2);
		new_order->item_quantities[i] = (int)strtod(token, NULL);
		token = strtok(NULL, MENU_DELIM);
	}
	free(temp);
	//free(token);
	
	return new_order;
}

void enqueue_order(Order* order, Restaurant* restaurant){
	QueueNode* new_node = (QueueNode *)malloc(sizeof(QueueNode));
	new_node->next = NULL;
	new_node->order = order;
	if (restaurant->pending_orders->head == NULL){	// empty queue
		restaurant->pending_orders->head = new_node;
		restaurant->pending_orders->tail = new_node;
	}
	else{	// already items in queue
		restaurant->pending_orders->tail->next = new_node;	// point current last element to this new node
		restaurant->pending_orders->tail = new_node;		// set new node as last element
	}
	restaurant->num_pending_orders += 1;
}

Order* dequeue_order(Restaurant* restaurant){
	if (restaurant->pending_orders->head == NULL){
		return NULL;
	}
	// Store node address and values before free/moving head pointer
	QueueNode* pop_node = restaurant->pending_orders->head;
	Order* pop_order = pop_node->order;

	restaurant->pending_orders->head = restaurant->pending_orders->head->next;
	free(pop_node);
	
	// Check if that was last node
	if (restaurant->pending_orders->head == NULL){
		restaurant->pending_orders->tail = NULL;
	}

	// Update fields
	restaurant-> num_completed_orders += 1;
	restaurant-> num_pending_orders -= 1;

	return pop_order;
}

double get_item_cost(char* item_code, Menu* menu){
	for(int i = 0; i < menu->num_items; i++){
		if(strcmp(item_code, menu->item_codes[i])==0){
			return menu->item_cost_per_unit[i];
		}
	}
	return 0;
}
double get_order_subtotal(Order* order, Menu* menu){
	double total = 0;
	double individual_price = 0;
	for(int i = 0; i < order->num_items; i++){
		individual_price = menu->item_cost_per_unit[i];
		individual_price *= get_item_cost(menu->item_codes[i], menu);
		total += individual_price;
	}
	return total;
}
double get_order_total(Order* order, Menu* menu){
	return get_order_subtotal(order, menu) * (1+(TAX_RATE/100));
}
int get_num_completed_orders(Restaurant* restaurant){
	return restaurant->num_completed_orders;
}
int get_num_pending_orders(Restaurant* restaurant){
	return restaurant->num_pending_orders;
}

void clear_order(Order** order){
	for(int i = 0; i < (*order)->num_items; i++){	
		free((*order)->item_codes[i]);
	}
	free((*order)->item_codes);
	free((*order)->item_quantities);
	free(*order);
}
void clear_menu(Menu** menu){
	for(int i = 0; i < (*menu)->num_items; i++){	
		free((*menu)->item_codes[i]);
		free((*menu)->item_names[i]);
	}
	free((*menu)->item_codes);
	free((*menu)->item_cost_per_unit);
	free((*menu)->item_names);
	free(*menu);
}
void close_restaurant(Restaurant** restaurant){
	free((*restaurant)->name);
	clear_menu(&((*restaurant)->menu));
	while((*restaurant)->num_pending_orders != 0){
		dequeue_order(*restaurant);
	}
	free((*restaurant)->pending_orders);
	free(*restaurant);
}

void print_menu(Menu* menu){
	fprintf(stdout, "--- Menu ---\n");
	for (int i = 0; i < menu->num_items; i++){
		fprintf(stdout, "(%s) %s: %.2f\n", 
			menu->item_codes[i], 
			menu->item_names[i], 
			menu->item_cost_per_unit[i]	
		);
	}
}


void print_order(Order* order){
	for (int i = 0; i < order->num_items; i++){
		fprintf(
			stdout, 
			"%d x (%s)\n", 
			order->item_quantities[i], 
			order->item_codes[i]
		);
	}
}


void print_receipt(Order* order, Menu* menu){
	for (int i = 0; i < order->num_items; i++){
		double item_cost = get_item_cost(order->item_codes[i], menu);
		fprintf(
			stdout, 
			"%d x (%s)\n @$%.2f ea \t %.2f\n", 
			order->item_quantities[i],
			order->item_codes[i], 
			item_cost,
			item_cost * order->item_quantities[i]
		);
	}
	double order_subtotal = get_order_subtotal(order, menu);
	double order_total = get_order_total(order, menu);
	
	fprintf(stdout, "Subtotal: \t %.2f\n", order_subtotal);
	fprintf(stdout, "               -------\n");
	fprintf(stdout, "Tax %d%%: \t$%.2f\n", TAX_RATE, order_total);
	fprintf(stdout, "              ========\n");
}