#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node* next;
};


struct node* getnode(int newdata){
    struct node* p=NULL;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=newdata;
    p->next=NULL;
    return p;
}

struct node* createlist(){
    return getnode(-1);
}

int insert_beg(struct node* p_head_node,int newdata){
    struct node* p=getnode(newdata);
    p->next=p_head_node->next;
    p_head_node->next=p;
}

int remove_beg(struct node* p_head_node){
    if  (p_head_node->next==NULL){
        return 0;
    }
    else{
        struct node* p=p_head_node->next;
        p_head_node->next=p->next;
        return p->data;
    }
}


int present(struct node* p_head_node,int newdata){
    struct node* p_run=p_head_node->next;
    while (p_run!=NULL){
        if (p_run->data==newdata){
            return 1;
        }
        p_run=p_run->next;
    }
    return 0;
}


int main(){
    struct node* p=createlist();
    insert_beg(p,2);
    insert_beg(p,3);
    printf("%d\n",remove_beg(p));
    printf("%d\n",present(p,2));
    return 0;
}