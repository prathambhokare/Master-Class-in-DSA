#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SUCCESS 1



typedef int data_t;
typedef struct node node_t;
typedef int status_t;
typedef int len_t;


struct node{
    data_t data;
    node_t* next;
    node_t* prev;
};

node_t* createlist();

status_t insert_beg(node_t* p_head_node,data_t data);
status_t insert_end(node_t* p_head_node,data_t data);
status_t insert_after(node_t* p_head_node,data_t e_data,data_t data);
status_t insert_before(node_t* p_head_node,data_t e_data,data_t data);


status_t remove_beg(node_t* p_head_node,data_t* value);
status_t remove_end(node_t* p_head_node,data_t* value);
status_t removenode(node_t* p_head_node,data_t data,data_t* value);

void reverse_list(node_t* p_head_node);
len_t length(node_t* p_head_node);
node_t* merge_list(node_t* l1,node_t* l2);

void destroy_list(node_t** p_head_node);

void show(node_t* p_head_node,const char* msg);
node_t* searchnode(node_t* p_head_node,data_t s_data);


node_t* getnode(data_t data);
void generic_insert(node_t* beg,node_t* mid,node_t* end);
void generic_delete(node_t* nvalue);

int main(){
    node_t* p1=createlist();
    for (int i=1;i<10;i++){
        insert_beg(p1,i*10);
    }
    show(p1,"list after insert beg:");
    insert_end(p1,20);
    show(p1,"list after insert end:");
    insert_after(p1,30,40);
    show(p1,"list after insert after:");
    insert_before(p1,40,40);
    show(p1,"list after insert before:");
    int a;
    remove_beg(p1,&a);
    printf("the value of removed node is [ %d ]",a);
    remove_end(p1,&a);
    printf("the value of removed node is [ %d ]",a);
    removenode(p1,40,&a);
    printf("the value of removed node is [ %d ]",a);
    show(p1,"list after remove node:");
    reverse_list(p1);
    show(p1,"list after reverse:");
    node_t* merge=merge_list(p1,p1);
    show(merge,"list after merge are:");
    destroy_list(&p1);
    if (p1){
        printf("destroyed succesfully\n");
    }
    return 0;
}


node_t* createlist(){
    return getnode(-1);
}

status_t insert_beg(node_t* p_head_node,data_t data){
    generic_insert(p_head_node,getnode(data),p_head_node->next);
    return SUCCESS;
}


status_t insert_end(node_t* p_head_node,data_t data){
    generic_insert(p_head_node->prev,getnode(data),p_head_node);
    return SUCCESS;
}


status_t insert_after(node_t* p_head_node,data_t e_data,data_t data){
    node_t* s_node=searchnode(p_head_node,e_data);
    /*generic_insert(s_node,getnode(data),s_node->next);*/
    return SUCCESS;
}



status_t insert_before(node_t* p_head_node,data_t e_data,data_t data){
    node_t* s_node=searchnode(p_head_node,e_data);
    generic_insert(s_node->prev,getnode(data),s_node);
    return SUCCESS;
}



status_t remove_beg(node_t* p_head_node,data_t* value){
    *value=p_head_node->next->data;
    generic_delete(p_head_node->next);
    return SUCCESS;
}



status_t remove_end(node_t* p_head_node,data_t* value){
    *value=p_head_node->prev->data;
    generic_delete(p_head_node->prev);
    return SUCCESS;
}



status_t removenode(node_t* p_head_node,data_t data,data_t* value){
    *value=data;
    generic_delete(searchnode(p_head_node,data));
    return SUCCESS;
}



void reverse_list(node_t* p_head_node){
    node_t* first=p_head_node->next;
    node_t* second=p_head_node->prev;
    int i=0;
    int j=length(p_head_node);
    while (i<=j){
        data_t temp=first->data;
        first->data=second->data;
        second->data=temp;
        first=first->next;
        second=second->prev;
        i++;
        j--;
    }
}



len_t length(node_t* p_head_node){
    len_t len=0;
    node_t* temp=p_head_node->next;
    while (temp!=p_head_node){
        len++;
        temp=temp->next;
    }
}


node_t* merge_list(node_t* l1,node_t* l2){
    node_t* temp1=l1->next;
    node_t* temp2=l2->next;
    node_t* merge=createlist();
    while (temp1->next!=l1 && temp2->next!=l1){
        if (temp1->data>temp2->data){
            insert_end(merge,temp2->data);
            temp2=temp2->next;
        }
        else{
            insert_end(merge,temp1->data);
            temp1=temp1->next;
        }
    }
    while (temp1!=l1){
        insert_end(merge,temp1->data);
        temp1=temp1->next;
    }
    while (temp2!=l2){
        insert_end(merge,temp2->data);
        temp2=temp2->next;
    }
    return merge;
}


void destroy_list(node_t** p_head_node){
    node_t* temp=*p_head_node;
    node_t* temp1=temp->next;
    node_t* temp2;
    while (temp1!=temp){
        temp2=temp1->next;
        free(temp1);
        temp1=temp2;
    }
    free(p_head_node);
}

void show(node_t* p_head_node,const char* msg){
    if (msg){
        puts(msg);
    }
    node_t* temp=p_head_node->next;
    while (temp!=p_head_node){
        printf("[ %d ] ",temp->data);
        temp=temp->next;
    }
}


node_t* searchnode(node_t* p_head_node,data_t s_data){
    node_t* temp=p_head_node->next;
    while (temp!=p_head_node){
        if (temp->data==s_data){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}


node_t* getnode(data_t data){
    node_t* newnode=(node_t*)malloc(sizeof(node_t));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(node_t));
    newnode->data=data;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}

void generic_insert(node_t* beg,node_t* mid,node_t* end){
    mid->next=end;
    mid->prev=beg;
    beg->next=mid;
    end->prev=mid;
}


void generic_delete(node_t* nvalue){
    node_t* temp=nvalue;
    nvalue->prev->next=nvalue->next;
    nvalue->next->prev=nvalue->prev;
    free(temp);
}
