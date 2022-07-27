/* Doubly Circular Linked List */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h> 

/* Symbolic constants */ 

#define TRUE 1
#define FALSE 0 
#define SUCCESS 1 
#define FAILURE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

/* typedefs */ 
typedef int int; 
typedef int int; 
typedef int len_t; 
typedef int bool; 
typedef struct node node_t; 
typedef node_t list_t; 

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

//to create the empty list which contain only the dummy node or head node
list_t* createList();

//function to insert the data
int insertbeg(node_t* p_head_node,int newdata);
int insertend(node_t* p_head_node,int newdata);
int insertafter(node_t* p_head_node,int e_data,int newdata);
int insertbefore(node_t* p_head_node,int e_data,int newdata);


//get the begnning and ending data
int getbeg(node_t* p_head_node,int* p_data);
int getend(node_t* p_head_node,int* p_data);
//get the beganning and ending data with removing the node
int popbeg(node_t* p_head_node,int* p_data);
int popend(node_t* p_head_node,int* p_data);

int removebeg(node_t* p_head_node);
int removeend(node_t* p_head_node);
int removedata(node_t* p_head_node,int r_data);

len_t getlength(node_t* p_head_node);
bool contains(node_t* p_head_node,int data);
bool islistempty(node_t* p_head_node);
int get_repeat_count(node_t* p_head_node,int search_data);
void show_list(struct node* p_head_node,const char* msg);

list_t* conacat_list(list_t* p1,list_t* p2);
list_t* merge_list(list_t* p1,list_t* p2);
list_t* get_reversed_list(list_t* p1);

int listtoarray(list_t* p,int** p_array,int* size);
list_t* arraytolist(int* p_array,int size);


int append_list(list_t* p1,list_t* p2);
int reverse_list(list_t* p1);
int destroy_list(list_t* p1);



/*Auxillary function*/
int generic_insert(node_t* beg,node_t* mid,node_t* end);
int generic_delete(node_t* deletenode);
node_t* locate_data(node_t* p_head_node,int search_data);
node_t* get_list_node(int newdata);

/*memory allocation*/
void* xmalloc(int size);

int main(){
    list_t* p=createList();
    for (int i=0;i<5;i++){
        insertbeg(p,(i+5)*10);
    }
    show_list(p,"after insert:");
    for (int i=0;i<5;i++){
        insertend(p,(i+5)*10);
    }
    show_list(p,"before insert");
    insertafter(p,60,70);
    show_list(p,"insert after");
    insertafter(p,60,70);
    show_list(p,"insert before");
    removebeg(p);
    show_list(p,"remove beganning");
    removeend(p);
    show_list(p,"remove end");
    removedata(p,70);
    show_list(p,"remove data");
    return 0;
}


list_t* createList(){
    node_t* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=-1;
    p->next=p;
    p->prev=p;
    return p;
}

bool islistempty(node_t* p_head_node){
    if (p_head_node->next==p_head_node && p_head_node->prev==p_head_node){
        return 1;
    }
    return 0;
}


node_t* get_list_node(int newdata){
    node_t* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=newdata;
    p->next=NULL;
    p->prev=NULL;
    return p;
}



int insertbeg(node_t* p_head_node,int newdata){
    struct node* p=get_list_node(newdata);
    p->prev=p_head_node;
    p->next=p_head_node->next;
    p_head_node->next->prev=p;
    p_head_node->next=p;
    return 1;
}

int insertend(node_t* p_head_node,int newdata){
    struct node* p=get_list_node(newdata);
    p->next=p_head_node;
    p->prev=p_head_node->prev;
    p_head_node->prev->next=p;
    p_head_node->prev=p;
}

int insertafter(node_t* p_head_node,int e,int newdata){
    struct node* p=locate_data(p_head_node,e);
    if (p==NULL){
        printf("node is not there in a linked list\n");
        return 0;
    }
    struct node*p1=get_list_node(newdata);
    p1->next=p->next;
    p1->prev=p;
    p->next->prev=p1;
    p->next=p1;
    return 1;
}

int insertbefore(node_t* p_head_node,int e,int newdata){
    struct node* p=locate_data(p_head_node,e);
    if (p==NULL){
        printf("node is not there in a linked list\n");
        return 0;
    }
    struct node*p1=get_list_node(newdata);
    p1->next=p;
    p1->prev=p->prev;
    p->prev->next=p1;
    p->prev=p1;
    return 1;
}

int removebeg(node_t* p_head_node){
    if (islistempty(p_head_node)){
        printf("list is empty\n");
        return 0;
    }
    struct node* temp=p_head_node->next;
    p_head_node->next=temp->next;
    temp->next->prev=p_head_node;
    free(temp);
    temp=NULL;
    return ;
}


int removeend(node_t* p_head_node){
    if (islistempty(p_head_node)){
        printf("list is empty\n");
        return 0;
    }
    struct node* temp=p_head_node->prev;
    p_head_node->prev=temp->prev;
    temp->prev->next=p_head_node;
    free(temp);
    temp=NULL;

}


int removedata(node_t* p_head_node,int data){
    struct node* p=locate_data(p_head_node,data);
    if (p==NULL){
        printf("list is empty\n");
        return 0;
    }
    struct node* temp=p;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    temp=NULL;
}


list_t* conacat_list(list_t* p1,list_t* p2){
    list_t* p=createList();
    if (islistempty(p1) && islistempty(p2)){
        return p;
    }
    p1->prev->next=p2->next;
    p1->prev=p2->prev;
    p2->next->prev=p1->prev;
    p2->prev->next=p1;
    return p;
}

list_t* merge_list(list_t* p1,list_t* p2){
    list_t* p=createList();
    struct node* temp1=p1->next;
    struct node* temp2=p2->next;
    while (temp1!=p1 && temp2!=p2){
        if (temp1->data>=temp2->data){
            insertend(p,temp2->data);
        }
        else{
            insertend(p,temp1->data);
        }
    }
    while (temp1!=p1){
        insertend(p,temp1->data);
    }
    while (temp2!=p2){
        insertend(p,temp2->data);
    }
    return p;
}


list_t* get_reversed_list(list_t* p1){
    list_t* p=createList();
    struct node* p_run;
    p_run=p1->next;
    while (p_run!=p1){
        insertbeg(p,p_run->data);
    }
    return p;
}

int
node_t* locate_data(node_t* p_head_node,int search_data){
    if (islistempty(p_head_node)){
        return NULL;
    }
    node_t* p_run;
    p_run=p_head_node->next;
    while (p_run!=p_head_node){
        if (p_run->data==search_data){
            return p_run;
        }
        p_run=p_run->next;
    }
    return NULL; 
}



void show_list(node_t* p_head_node,const char* msg){
    node_t* p_run;
    p_run=p_head_node->next;
    puts(msg);
    printf("[BEG]<->");
    while (p_run!=p_head_node){
        printf("[%d]<->",p_run->data);
        p_run=p_run->next;
    }
    printf("[END]\n");
}