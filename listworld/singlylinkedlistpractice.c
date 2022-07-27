#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

struct node{
    int data;
    struct node* next;
};


list_t* createlist();

int insert_beg(node_t* p_head_node,int newdata);
int insert_end(node_t* p_head_node,int newdata);
int insert_before(node_t* p_head_node,int s_data,int newdata);
int insert_after(node_t* p_head_node,int s_data,int newdata);


int remove_beg(node_t* p_head_node);
int remove_end(node_t* p_head_node);
int removenode(node_t* p_head_node,int s_data);

len_t getlength(node_t* p_head_node);

list_t* concat(list_t* p1,list_t* p2);
list_t* merge(list_t* p1,list_t* p2);
list_t* getreversedlist(node_t* p_head_node);



void show_list(node_t* p_head_node,const char* msg);

//auxillary routine

void* xmalloc(size_t nr_bytes);
node_t* getnode(int newdata);
void generic_insert(node_t* beg,node_t* mid,node_t* end);
node_t* getlastnode(node_t* p_head_node);
node_t* getsearchnode(node_t* p_head_node,int s_data);
Bool isListempty(node_t* p_head_node);
node_t* getprevtolastnode(node_t* p_head_node);
node_t* getprevtospecificnode(node_t* p_head_node,int s_data);
void generic_delete(node_t* beg,node_t* mid,node_t* end);


int main(){
    list_t* p=createlist();
    for (int i=0;i<10;i++){
        insert_beg(p,(i+1)*10);
    }
    show_list(p,"inserting to list");
    insert_end(p,20);
      show_list(p,"inserting to list");
    node_t* prev=getprevtolastnode(p);
    printf("previous data is %d\n",prev->data);
    node_t* prev2=getprevtospecificnode(p,40);
    printf("previous is %d\n",prev2->data);
    insert_after(p,50,40);
       show_list(p,"inserting to list");
    insert_before(p,50,30);
     show_list(p,"inserting to list");
    remove_beg(p);
     show_list(p,"inserting to list");
    remove_end(p);
       show_list(p,"inserting to list");
    removenode(p,50);
       show_list(p,"inserting to list");
    list_t* p2=createlist();
    for (int i=0;i<10;i++){
        insert_beg(p2,(i+1)*10);
    }
    list_t* concatlist=concat(p,p2);
       show_list(p,"inserting to list");
    list_t* mergelist=merge(p,p2);
       show_list(mergelist,"inserting to list");
    return 0;
}

list_t* createlist(){
    return getnode(-1);
}

int insert_beg(node_t* p_head_node,int newdata){
    generic_insert(p_head_node,getnode(newdata),p_head_node->next);
    return 1;
}




int insert_end(node_t* p_head_node,int newdata){
    generic_insert(getlastnode(p_head_node),getnode(newdata),NULL);
}



int insert_after(node_t* p_head_node,int s_data,int newdata){
    node_t* curnode=getsearchnode(p_head_node,s_data);
    generic_insert(curnode,getnode(newdata),curnode->next);
}


int insert_before(node_t* p_head_node,int s_data,int newdata){
    node_t* curnode=getsearchnode(p_head_node,s_data);
    generic_insert(getprevtospecificnode(p_head_node,s_data),getnode(newdata),curnode);
}



int remove_beg(node_t* p_head_node){
    if (isListempty(p_head_node)){
        printf("list is empty\n");
        exit(0);
    }
    generic_delete(p_head_node,p_head_node->next,p_head_node->next->next);
}



int remove_end(node_t* p_head_node){
    if (isListempty(p_head_node)){
        printf("list is empty\n");
        exit(0);
    }
    generic_delete(getprevtolastnode(p_head_node),getlastnode(p_head_node),NULL);
}



int removenode(node_t* p_head_node,int s_data){
    if (isListempty(p_head_node)){
        printf("list is empty\n");
        exit(0);
    }
    node_t* curnode=getsearchnode(p_head_node,s_data);
    generic_delete(getprevtospecificnode(p_head_node,s_data),getsearchnode(p_head_node,s_data),curnode->next);
}

len_t getlength(node_t* p_head_node){
    node_t* p_run=NULL;
    p_run=p_head_node->next;
    int length=0;
    while (p_run!=NULL){
        length=length+1;
        p_run=p_run->next;
    }
}



list_t* concat(list_t* p1,list_t* p2){
    node_t* lastnode=getlastnode(p1);
    lastnode->next=p2->next;
    return p1;
    free(p2);
    p2=NULL;
}



list_t* merge(list_t* p1,list_t* p2){
    node_t* temp1=p1->next;
    node_t* temp2=p2->next;
    list_t* mergelist=createlist();
    while (TRUE){
        if (temp2==NULL){
            while(temp1!=NULL){
                insert_end(mergelist,temp1->data);
                temp1=temp1->next;
            }
            break;
        }
         if (temp1==NULL){
            while(temp2!=NULL){
                insert_end(mergelist,temp2->data);
                temp2=temp2->next;
            }
            break;
        }
        if (temp1->data>temp2->data){
            insert_end(mergelist,temp2->data);
            temp2=temp2->next;
        }
        else{
            insert_end(mergelist,temp1->data);
            temp1=temp1->next;
        }
    }
    while(temp1!=NULL){
        insert_end(mergelist,temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        insert_end(mergelist,temp2->data);
        temp2=temp2->next;
    }
    return mergelist;
}


list_t* getreversedlist(list_t* p1){
    list_t* reverselist=createlist();
    node_t* temp=p1->next;
    while (p1!=NULL){
        insert_beg(reverselist,temp->data);
        temp=temp->next;
    }
}


void show_list(node_t* p_head_node,const char* msg){
    puts(msg);
    node_t* p_run=p_head_node->next;
    printf("[BEG]<->");
    while (p_run!=NULL){
        printf("%d<->",p_run->data);
        p_run=p_run->next;
    }
    printf("[END]\n");
}



node_t* getlastnode(node_t* p_head_node){
    if  (isListempty(p_head_node)){
        return NULL;
    }
    node_t* p_run=p_head_node->next;
    while (p_run->next!=NULL){
        p_run=p_run->next;
    }
    return p_run;
}

node_t* getsearchnode(node_t* p_head_node,int s_data){
    struct node* p_run=p_head_node->next;
    while (p_run!=NULL){
        if (p_run->data==s_data){
            return p_run;
        }
        p_run=p_run->next;
    }
}


Bool isListempty(node_t* p_head_node){
    if (p_head_node->next==NULL){
        return TRUE;
    }
    return FALSE;
}



node_t* getprevtolastnode(node_t* p_head_node){
    if  (isListempty(p_head_node)){
        return NULL;
    }
    node_t* p_run=p_head_node->next;
    node_t* prev=p_run;
    while (p_run->next!=NULL){
        prev=p_run;
        p_run=p_run->next;
    }
    return prev;
}


node_t* getprevtospecificnode(node_t* p_head_node,int s_data){
    struct node* p_run=p_head_node->next;
    node_t* prev=p_run;
    while (p_run!=NULL){
        prev=p_run;
        p_run=p_run->next;
        if (p_run->data==s_data){
            break;
        }
    }
    return prev;
}


void generic_delete(node_t* prev,node_t* mid,node_t* last){
    prev->next=last;
    free(mid);
    mid=NULL;
}


void* xmalloc(size_t nr_bytes){
    void* p=NULL;
    p=malloc(nr_bytes);
    if (p==NULL){
        printf("Error is occured\n");
        exit(0);
    }
    memset(p,0,nr_bytes);
    return p;
}




node_t* getnode(int newdata){
    node_t* p=NULL;
    p=(node_t*)xmalloc(sizeof(node_t));
    p->data=newdata;
    p->next=NULL;
    return p;
}



void generic_insert(node_t* beg,node_t* mid,node_t* end){
    node_t* b=beg;
    node_t* m=mid;
    node_t* e=end;
    b->next=m;
    m->next=e;
}