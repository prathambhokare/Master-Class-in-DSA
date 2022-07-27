#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SUCCESS 1

typedef int data_t;
typedef struct node node_t;
typedef int len_t;
typedef int status_t;


struct node{
    int data;
    node_t* next;
};


node_t* createlist();

status_t insert_beg(node_t* p_head_node,data_t data);
status_t insert_end(node_t* p_head_node,data_t data);
status_t insert_after(node_t* p_head_node,data_t e_data,data_t data);
status_t insert_before(node_t* p_head_node,data_t e_data,data_t data);


status_t removebeg(node_t* p_head_node,data_t* value);
status_t removened(node_t* p_head_node,data_t* value);
status_t removenode(node_t* p_head_node,data_t data,data_t* value);



void reverse_list(node_t* p_head_node);
void reverse_list1(node_t* p_head_node);
node_t* merge_list(node_t* l1,node_t* l2);





void show(node_t* p_head_node,const char* msg);
len_t length(node_t* p_head_node);
node_t* search(node_t* p_head_node,data_t s_data);

node_t* getnode(data_t data);

int main(){
    node_t* p1=createlist();
    for (int i=1;i<10;i++){
        insert_beg(p1,i*10);
    }
    show(p1,"insert at beg");
    insert_end(p1,20);
    show(p1,"insert at end");
    insert_end(p1,20);
    show(p1,"insert at end");
    insert_after(p1,40,30);
    show(p1,"insert after");
    insert_before(p1,40,40);
    show(p1,"insert before");
    int a;
    removebeg(p1,&a);
    printf("[ %d ]",a);
    a=0;
    show(p1,"after removinfg the beg:");
    removened(p1,&a);
    printf("[ %d ]",a);
    show(p1,"after removing the end:");
    removenode(p1,40,&a);
    printf("[ %d ]",a);
    show(p1,"after removed node:");
    reverse_list(p1);
    show(p1,"after reverse list:");
    node_t* merge=createlist();
    merge=merge_list(p1,p1);
    show(p1,"after merge list:");
    printf("[ %d ]",merge->next->data);
    reverse_list1(p1);
    show(p1,"aftrer reversing the linked list:");
    return 0;
}


node_t* createlist(){
    return getnode(-1);
}


status_t insert_beg(node_t* p_head_node,data_t data){
    node_t* newnode=getnode(data);
    newnode->next=p_head_node->next;
    p_head_node->next=newnode;
    return SUCCESS;
}


status_t insert_end(node_t* p_head_node,data_t data){
    node_t* newnode=getnode(data);
    node_t* prev;
    node_t* temp=p_head_node->next;
    while (temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=newnode;
    return SUCCESS;
}



status_t insert_after(node_t* p_head_node,data_t e_data,data_t data){
    node_t* newnode=getnode(data);
    node_t* s_node=search(p_head_node,e_data);
    newnode->next=s_node->next;
    s_node->next=newnode;
    return SUCCESS;
}



status_t insert_before(node_t* p_head_node,data_t e_data,data_t data){
    node_t* newnode=getnode(data);
    node_t* prev;
    node_t* temp=p_head_node->next;
    while (1){
        prev=temp;
        temp=temp->next;
        if (temp->data==e_data){
            break;
        }
    }
    newnode->next=temp;
    prev->next=newnode;
    return SUCCESS;
}



status_t removebeg(node_t* p_head_node,data_t* value){
    node_t* temp=p_head_node->next;
    p_head_node->next=temp->next;
    *value=temp->data;
    free(temp);
    return SUCCESS;
}




status_t removened(node_t* p_head_node,data_t* value){
    node_t* prev;
    node_t* temp=p_head_node->next;
    while (1){
        prev=temp;
        temp=temp->next;
        if (temp->next==NULL){
            break;
        }
    }
    *value=temp->data;
    prev->next=NULL;
    free(temp);
    return SUCCESS;
}




status_t removenode(node_t* p_head_node,data_t data,data_t* value){
    node_t* temp=p_head_node->next;
    node_t* prev;
    while (1){
        prev=temp;
        temp=temp->next;
        if (temp->data==data){
            break;
        }
    }
    *value=data;
    prev->next=temp->next;
    free(temp);
    return SUCCESS;
}



void show(node_t* p_head_node,const char* msg){
    if (msg){
        puts(msg);
    }
    node_t* temp=p_head_node->next;
    while (temp!=NULL){
        printf("[ %d ]",temp->data);
        temp=temp->next;
    }
}


len_t length(node_t* p_head_node){
    len_t len=0;
    node_t* temp=p_head_node->next;
    while (temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}



void reverse_list(node_t* p_head_node){
    int a;
    int value=p_head_node->next->data;
    insert_end(p_head_node,p_head_node->next->data);
    removebeg(p_head_node,&a);
    len_t len=length(p_head_node);
    for (int i=0;i<len-1;i++){
        insert_after(p_head_node,value,p_head_node->next->data);
        removebeg(p_head_node,&a);
    }
    insert_end(p_head_node,p_head_node->next->data);
    removebeg(p_head_node,&a);
}


void reverse_list1(node_t* p_head_node){
    node_t* temp=p_head_node->next;
    node_t* cur=NULL;
    node_t* prev=NULL;
    while (temp!=NULL){
        prev=temp;
        temp=temp->next;
        prev->next=cur;
        cur=prev;
    }
    p_head_node->next=prev;
}


node_t* merge_list(node_t* l1,node_t* l2){
    node_t* temp1=l1->next;
    node_t* temp2=l2->next;
    node_t* merge=createlist();
    while (temp1->next!=NULL && temp2->next!=NULL){
        if (temp1->data>temp2->data){
            insert_beg(merge,temp2->data);
            temp2=temp2->next;
        }
        else{
            insert_beg(merge,temp1->data);
            temp1=temp1->next;
        }
    }
    while (temp1!=NULL){
        insert_beg(merge,temp1->data);
        temp1=temp1->next;
    }
    while (temp2!=NULL){
        insert_beg(merge,temp2->data);
        temp2=temp2->next;
    }
    return merge;
}




node_t* search(node_t* p_head_node,data_t s_data){
    node_t* temp=p_head_node->next;
    while (temp!=NULL){
        if (temp->data==s_data){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}


node_t* getnode(data_t data){
    node_t* newnode=NULL;
    newnode=(node_t*)malloc(sizeof(node_t));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(newnode));
    newnode->data=data;
    newnode->next=NULL;
}