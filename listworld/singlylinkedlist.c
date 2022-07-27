#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node* next;
};


struct node* createlist();
struct node* getnode(int newdata);
void showlist(struct node* p_head_node);
struct node* search(struct node* p_head_node,int search_data);
int listempty(struct node* p_head_node);
int getlength(struct node* p_head_node);
int insertbeg(struct node* p_head_node,int newdata);
int insertend(struct node* p_head_node,int newdata);
int insertafter(struct node* p_head_node,int existing_data,int newdata);
int insertbefore(struct node* p_head_node,int existing_data,int newdata);
int removebeg(struct node* p_head_node);
int removeend(struct node* p_head_node);
int removedata(struct node* p_head_node,int existing_data);
struct node* concatlist(struct node* p1,struct node* p2);
struct node* mergelist(struct node* p1,struct node* p2);
struct node* get_reversed_list(struct node* p_head_node);
void reverse_list(struct node* p_head_node);
int destroy_list(struct node** pp_list)


int main(){
    struct node* p=createlist();
    insertend(p,90);
    for (int i=0;i<5;i++){
        insertbeg(p,(i+10)*10);
    }
    insertend(p,150);
    insertafter(p,150,170);
    insertbefore(p,150,140);
    removebeg(p);
    removeend(p);
    showlist(p);
    removedata(p,100);
    showlist(p);
    struct node* p1=createlist();
    for (int i=0;i<5;i++){
        insertbeg(p1,(i+10)*10);
    }
    struct node* p2=concatlist(p,p1);
    showlist(p2);
    struct node* p3=mergelist(p,p2);
    showlist(p3);
    struct node* p4=get_reversed_list(p3);
    showlist(p4);
    printf("length is [%d]\n",getlength(p4));
    struct node* p5=createlist();
    insertbeg(p5,10);
    insertbeg(p5,20);
    insertbeg(p5,30);
    insertbeg(p5,40);
    showlist(p5);
    reverse_list(p5);
    showlist(p5);
    //destroy_list(&p5);
    return 0;
}


struct node* createlist(){
    return getnode(-1);
}



struct node* getnode(int newdata){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=newdata;
    p->next=NULL;
    return p;
}

struct node* search(struct node* p_head_node,int search_data){
    struct node* p_run=NULL;
    p_run=p_head_node->next;
    while (p_run!=NULL){
        if (p_run->data==search_data){
            return p_run;
        }
        p_run=p_run->next;
    }
    return NULL;
}

int listempty(struct node* p_head_node){
    if (p_head_node->next==NULL){
        return 1;
    }
    return 0;
}


int getlength(struct node* p_head_node){
    struct node* p_run=p_head_node->next;
    int length=0;
    while (p_run!=NULL){
        length++;
        p_run=p_run->next;
    }
    return length;
}

int insertbeg(struct node* p_head_node,int newdata){
    struct node* new_node=NULL;
    new_node=getnode(newdata);
    new_node->next=p_head_node->next;
    p_head_node->next=new_node;
    return 1;
}

int insertend(struct node* p_head_node,int newdata){
    struct node* prev=p_head_node;
    struct node* p_run=p_head_node;
    while (p_run!=NULL){
        prev=p_run;
        p_run=p_run->next;
    }
    prev->next=getnode(newdata);
    return 1;
}


int insertafter(struct node* p_head_node,int existing_data,int newdata){
    struct node* p_search=search(p_head_node,existing_data);
    struct node* newnode=getnode(newdata);
    newnode->next=p_search->next;
    p_search->next=newnode;
    return 1;
}

int insertbefore(struct node* p_head_node,int existing_data,int newdata){
    struct node* prev=p_head_node;
    struct node* p_run=p_head_node->next;
    while (p_run!=NULL){
        prev=p_run;
        p_run=p_run->next;
        if (p_run->data==existing_data){
            break;
        }
    }
    struct node* newnode=getnode(newdata);
    newnode->next=prev->next;
    prev->next=newnode;
    return 1;
}

int removebeg(struct node* p_head_node){
    int data=0;
    if (listempty(p_head_node)){
        printf("list is empty\n");
        return 0;
    }
    else{
        struct node* temp=p_head_node->next;
        data=p_head_node->next->data;
        p_head_node->next=p_head_node->next->next;
        free(temp);
        temp=NULL;
    }
    return data;
}

int removeend(struct node* p_head_node){
    struct node* prev=p_head_node;
    struct node* p_run=p_head_node;
    while (p_run->next!=NULL){
        prev=p_run;
        p_run=p_run->next;
    }
    struct node* temp=p_run;
    prev->next=temp->next;
    free(temp);
    temp=NULL;
    return 1;
}

int removedata(struct node* p_head_node,int existing_data){
    struct node* prev=p_head_node;
    struct node* p_run=p_head_node->next;
    while (p_run!=NULL){
        prev=p_run;
        p_run=p_run->next;
        if (p_run->data==existing_data){
            break;
        }
    }
    struct node* temp=p_run;
    prev->next=temp->next;
    free(temp);
    temp=NULL;
}

struct node* concatlist(struct node* p1,struct node* p2){
    struct node* prev=p1;
    struct node* p_run=p1;
    while (p_run!=NULL){
        prev=p_run;
        p_run=p_run->next;
    }
    prev->next=p2->next;
    free(p2);
    p2=NULL;
    return p1;
}


struct node* mergelist(struct node* p1,struct node* p2){
    struct node* p3=createlist();
    struct node* temp1=p1->next;
    struct node* temp2=p2->next;
    while (1){
        if (temp1==NULL){
            while (temp2!=NULL){
                insertend(p3,temp2->data);
                temp2=temp2->next;
            }
            break;
        }
        if (temp2==NULL){
            while (temp1!=NULL){
                insertend(p3,temp1->data);
                temp1=temp1->next;
            }
            break;
        }
        if (temp1->data<=temp2->data){
            insertend(p3,temp1->data);
            temp1=temp1->next;
        }
        else{
            insertend(p3,temp2->data);
            temp2=temp2->next;
        }
    }
    return p3;
}

struct node* get_reversed_list(struct node* p_head_node){
    struct node* p=createlist();
    struct node* p_run=p_head_node->next;
    while (p_run!=NULL){
        insertbeg(p,p_run->data);
        p_run=p_run->next;
    }
    return p;
}


void reverse_list(struct node* p_head_node){
    if (!listempty(p_head_node)){
        int length=getlength(p_head_node);
        int existingdata=p_head_node->next->data;
        insertend(p_head_node,p_head_node->next->data);
        removebeg(p_head_node);
        for (int i=0;i<length-2;i++){
            insertbefore(p_head_node,existingdata,p_head_node->next->data);
            existingdata=removebeg(p_head_node);
        }
    }
}


int destroy_list(struct node** pp_list)
{
    struct node* p_list = *pp_list; 
    struct node* p_run, *p_run_next; 
    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next; 
        free(p_run); 
    }
    free(p_list); 
    *pp_list = NULL; 
    return 1;
}



void showlist(struct node* p_head_node){
    struct node* p_run=NULL;
    p_run=p_head_node->next;
    printf("[BEG]<->");
    while (p_run!=NULL){
        printf("[%d]<->",p_run->data);
        p_run=p_run->next;
    }
    printf("[END]\n");
}