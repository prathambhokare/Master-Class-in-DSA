#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int status;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};



struct node* createList();
struct node* getnode(int data);


status insertbeg(struct node* p_head_node,int data);
status insertend(struct node* p_head_node,int data);
status insertafter(struct node* p_head_node,int data);
status insertbefore(struct node* p_head_node,int data);


void showList(struct node* p_head_node);


int main(){
    struct node* p=createList();
    printf("%d\n",p->data);
    insertbeg(p,10);
    /*for (int i=0;i<5;i++){
        insertbeg(p,(i+1)*5);
    }*/
    //showList(p);
    return 0;
}

struct node* getnode(int newdata){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=newdata;
    return p;
}



struct node* createList(){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    memset(p,0,sizeof(struct node));
    p->data=-1;
    return p;
}


void showList(struct node* p_head_node){
    struct node* p_run=p_head_node->next;
    printf("[BEG]<->");
    while(p_run!=p_head_node){
        printf("[%d]<->",p_run->data);
        p_run=p_run->next;
    }
    printf("[END]\n");
}


status insertbeg(struct node* p_head_node,int newdata){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    memset(p,0,sizeof(struct node));
    p->data=newdata;
    p->next=p_head_node->next;
    p->prev=p_head_node;
    p_head_node->next->prev=p;
    p_head_node->next=p;
    return 1;
}