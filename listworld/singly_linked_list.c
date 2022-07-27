#pragma once

#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

typedef int int;
typedef int int; 
typedef int len_t; 
typedef int Bool;

typedef struct node node_t; 
typedef node_t list_t; 

struct node
{
	int data;
	struct node* next; 
}; 


list_t* create_list(void){
	return get_node(-1);
} 

int insert_start(list_t* p_list, int new_data){
	generic_insert(p_list,get_node(new_data),p_list->next);
}

int insert_end(list_t* p_list, int new_data){
	generic_insert(get_last_node(p_list),getnode(new_data),NULL);
}

int insert_after(list_t* p_list, int e_data, int new_data); 
int insert_before(list_t* p_list, int e_data, int new_data); 

int get_start(list_t* p_list, int* p_start_data); 
int get_end(list_t* p_list, int* p_end_data); 
int pop_start(list_t* p_list, int* p_start_data); 
int pop_end(list_t* p_list, int* p_end_data); 

int remove_start(list_t* p_list); 
int remove_end(list_t* p_list); 
int remove_data(list_t* p_list, int r_data); 

len_t get_length(list_t* p_list); 
Bool is_empty(list_t* p_list); 
Bool is_member(list_t* p_list, int s_data); 
void show(list_t* p_list, const char* msg); 

list_t* concat(list_t* p_list_1, list_t* p_list_2); 
list_t* merge(list_t* p_list_1, list_t* p_list_2); 
list_t* get_reversed_list(list_t* p_list_1); 

int append(list_t* p_list_1, list_t* p_list_2); 
int revese_list(list_t* p_list); 

void to_array(list_t* p_list, int** p_array, size_t* p_size); 
list_t* to_list(int* p_array, size_t size); 

int destroy_list(list_t** pp_list); 

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end){
	p_beg->next=p_mid;
	p_mid->next=p_end;
}


static void generic_delete(node_t* p_prev_node, node_t* p_delete_node){
	p_prev_node->next=p_delete_node->next;
	free(p_delete_node);
	p_delete_node=NULL;
} 

static node_t* search_node(list_t* p_list, int s_data){
	list_t* p_run=p_list->next;
	while (p_run!=NULL){
		if (p_run->data==s_data){
			return p_run;
		}
	}
	return NULL;
}

static void get_node_and_prev(list_t* p_list, int s_data, node_t** pp_node, node_t** pp_prev_node){
	list_t* p_run=p_list->next;
	list_t* prev=p_list->next;
	while (p_run->next!=NULL){
		prev=p_run;
		if (p_run==s_data){
			*pp_node=p_run;
			break;
		}
		p_run=p_run->next;
	}
	*pp_prev_node=prev;
}

static void get_last_node(list_t* p_list, node_t** pp_last_node){
	list_* p_run=p_list->next;
	while (p_run->next!=NULL){
		p_run=p_run->next;
	}
	return p_run;
}

static void get_last_node_and_prev(list_t* p_list, node_t** pp_node, node_t** pp_prev_node){
	list_t* p_run=p_list->next;
	list_t* prev=p_list->next;
	while (p_run->next!=NULL){
		prev=p_run;
		p_run=p_run->next;
	}
	*pp_node=p_run;
	*pp_prev_node=prev;
}


static node_t* get_node(int new_data){
	node_t* p=NULL;
	p=(node_t*)malloc(sizeof(node_t));
	if (p==NULL){
		printf("Error is occured\n");
	}
	memset(p,0,sizeof(node_t));
	p->data=new_data;
	p->next=NULL;
	return p;
}

static void* xmalloc(size_t nr_bytes);


int main(){
	list_t* p=create_list();
	return 0;
}