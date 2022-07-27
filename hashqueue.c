#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node* prev;
    struct node* next;
};



struct hash{
    int key;
    struct hash* next;
    struct hash* prev;
    struct node* list_head_node;
};


struct node* createlist();
int insertend(struct node* list_head_node,int value);
int removdenode(struct node* list_head_node,int value);
struct node* search(struct node* list_head_node,int s_data);
struct node* getnode(int value);



struct hash* createhashq();
int insertkey(struct hash* hashq,int key);
int removekey(struct hash* hashq,int key);
int addvalue(struct hash* hashq,int value,int k);
int hash(int value,int k);
void dispalyhashq(struct hash* hashq);
struct hash* searchkey(struct hash* hashq,int key);



int main(){
    //struct node* p=createlist();
    //insertend(p,1);
    //insertend(p,2);
    //removdenode(p,1);
    //printf("%d",p->next->data);
    //struct node* s_node=NULL;
    //s_node=search(p,1);
    //printf("%d ",s_node->data);
    struct hash* p1=createhashq();
    insertkey(p1,0);
    insertkey(p1,1);
    insertkey(p1,2);
    removekey(p1,1);
    //printf("%d",p1->prev->key);
    addvalue(p1,6,3);
    dispalyhashq(p1);
    return 0;
}



struct hash* createhashq(){
    struct hash* newnode=NULL;
    newnode=(struct hash*)malloc(sizeof(struct hash));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct hash));
    newnode->key=-1;
    newnode->list_head_node=NULL;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}



int insertkey(struct hash* hashq,int key){
    struct hash* temp=hashq;
    struct hash* newnode=NULL;
    newnode=(struct hash*)malloc(sizeof(struct hash));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct hash));
    newnode->key=key;
    newnode->list_head_node=createlist();
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
    return 1;
}




int removekey(struct hash* hashq,int key){
    struct hash* temp=hashq->next;
    struct hash* found=NULL;
    found=searchkey(hashq,key);
    found->prev->next=found->next;
    found->next->prev=found->prev;
    struct node* temp1=found->list_head_node->next;
    while (temp1!=found->list_head_node){
        removdenode(found->list_head_node,temp1->data);
        temp1=temp1->next;
    }
    free(temp->list_head_node);
    free(found);
    found=NULL;
    return 1;
}




int addvalue(struct hash* hashq,int value,int k){
    int key=hash(value,k);
    printf("the key is %d\n",key);
    struct hash* temp=searchkey(hashq,key);
    if (temp->list_head_node==NULL){
        printf("the list is not created for the this key\n");
    }
    else{
        printf("the key is present is hashqueue\n");
    }
    insertend(temp->list_head_node,value);
    return 1;    
}





int hash(int value,int k){
    return value%k;
}



void dispalyhashq(struct hash* hashq){
    struct hash* temp=hashq->next;
    while (temp!=hashq){
        printf("[ %d ]",temp->key);
        struct node* temp1=temp->list_head_node->next;
        while (temp1!=temp->list_head_node){
            printf(" [ %d ] ",temp1->data);
            temp1=temp1->next;
        }
        printf("\n");
        temp=temp->next;
    }
    
}


struct hash* searchkey(struct hash* hashq,int key){
    struct hash* temp=hashq->next;
    struct hash* found=NULL;
    while (temp!=hashq){
        if (temp->key==key){
            found=temp;
            break;
        }
        temp=temp->next;
    }
    return found;
}


struct node* createlist(){
    return getnode(-1);
}

int insertend(struct node* list_head_node,int value){
    struct node* temp=list_head_node;
    struct node* newnode=getnode(value);
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
    return 1;
}

int removdenode(struct node* list_head_node,int value){
    struct node* s_node=NULL;
    s_node=search(list_head_node,value);
    s_node->prev->next=s_node->next;
    s_node->next->prev=s_node->prev;
    free(s_node);
    s_node=NULL;
    return 1;
}



struct node* search(struct node* list_head_node,int s_data){
    struct node* temp=list_head_node->next;
    struct node* temp1=NULL;
    int found=0;
    while (temp!=list_head_node){
        if (temp->data==s_data){
            temp1=temp;
            found=1;
            break;
        }
        temp=temp->next;
    }
    return temp1;
}


struct node* getnode(int value){
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct node));
    newnode->data=value;
    newnode->next=newnode;
    newnode->prev=newnode;
}
