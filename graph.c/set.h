#include "list.h"

#define SET_ELEMENT_EXISTS  4 

typedef list_t set_t; 

struct node* create_set(void); 
struct node* set_union(struct node* p_set_1, struct node* p_set_2); 
struct node* set_intersection(struct node* p_set_1, struct node* p_set_2); 
struct node* st_diff(struct node* p_set_1, struct node* p_set_2); 
struct node* set_symmetric_difference(struct node* p_set_1, struct node* p_set_2); 
int is_subset(struct node* p_set_1, struct node* p_set_2); 
int is_superset(struct node* p_set_1, struct node* p_set_2); 
int add_element(struct node* p_set, int element); 
int remove_element(struct node* p_set, int element);  
int is_member(struct node* p_set, int data); 