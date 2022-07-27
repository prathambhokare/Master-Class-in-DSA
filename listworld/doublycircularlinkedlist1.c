#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*doubly circular linked list using the dummy node approach
    node ==> [data,address of next node,address of previous node]
    [prev [-1] next]//this is dummy node
*/


struct node{
    int data;
    struct node* next;
    struct node* prev; 
};

struct node* createList(){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured");
    }
    memset(p,0,sizeof(struct node));
    p->data=-1;
    p->next=p;
    p->prev=p;
    return p;
}


struct node* getnode(int new_data){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=new_data;
    return p;
}


void generic_insert(struct node* beg,struct node* end,int new_data){
    struct node* p=getnode(new_data);
    if (p==NULL){
        printf("Error is occured\n");
    }
    beg->next=p;
    p->prev=beg;
    p->next=end;
    end->prev=p;
}


struct node* search(struct node* p_head_node,int search_data){
    struct node* p=p_head_node;
    p=p->next;
    while (p!=p_head_node){
        if (p->data==search_data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int insert_start(struct node* p_head_node,int new_data){
    struct node* p=getnode(new_data);
    if (p==NULL){
        printf("Error is occured\n");
        return 0;
    }
    /*p->next=p_head_node->next;
    p->prev=p_head_node;
    p_head_node->next->prev=p;
    p_head_node->next=p;*/
    generic_insert(p_head_node,p_head_node->next,new_data);
    return 1;
}



int insert_end(struct node* p_head_node,int new_data){
    struct node* p=getnode(new_data);
    if (p==NULL){
        printf("Error is occured\n");
    }
    /*p->next=p_head_node;
    p->prev=p_head_node->prev;
    p_head_node->prev->next=p;
    p_head_node->prev=p;*/
    generic_insert(p_head_node->prev,p_head_node,new_data);
    return 1;
}


int insert_after(struct node* p_head_node,int search_data,int new_data){
    struct node* p=search(p_head_node,search_data);
    if (p==NULL){
        return 0;
    }
    generic_insert(p,p->next,new_data);
    return 1;
}


int insert_before(struct node* p_head_node,int serach_data,int new_data){
    struct node* p=search(p_head_node,serach_data);
    if (p==NULL){
        return 0;
    }
    generic_insert(p->prev,p,new_data);
}

int isempty(struct node* p_head_node){
    if (p_head_node->next==p_head_node && p_head_node->prev==p_head_node){
        return 1;
    }
    return 0;
}


void generic_delete(struct node* beg){
    struct node* p=beg;
    beg->prev->next=beg->next;
    beg->next->prev=beg->prev;
    free(p);
    p=NULL;
}

int remove_beg(struct node* p_head_node){
    if (isempty(p_head_node)){
        printf("Error is occured\n");
        return 0;
    }
    /*struct node* p=p_head_node->next;
    p_head_node->next->next->prev=p_head_node;
    p_head_node->next=p_head_node->next->next;
    free(p);
    p=NULL;*/
    generic_delete(p_head_node->next);
    return 1;
}

int remove_end(struct node* p_head_node){
    if (isempty(p_head_node)){
        printf("Error is occured\n");
        return 0;
    }
    /*struct node* p=p_head_node->prev;
    p_head_node->prev->prev->next=p_head_node;
    p_head_node->prev=p_head_node->prev->prev;
    free(p);
    p=NULL;*/
    generic_delete(p_head_node->prev);
    return 1;
}


int remove_node(struct node* p_head_node,int search_data){
    struct node* p=search(p_head_node,search_data);
    if (isempty(p)){
        printf("Error is occured\n");
        return 0;
    }
    generic_delete(p);
    return 1;
}
void display(struct node* p_head_node){
    struct node* p=p_head_node;
    p=p->next;
    while (p!=p_head_node){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    struct node* p=createList();
    insert_start(p,2);
    insert_start(p,3);
    insert_start(p,4);
    insert_start(p,5);
    insert_start(p,6);
    insert_end(p,7);
    insert_after(p,2,8);
    insert_before(p,9,8);
    remove_beg(p);
    remove_end(p);
    remove_node(p,4);
    printf("%d\n",p->prev->data);
    display(p);
    return 0;
}