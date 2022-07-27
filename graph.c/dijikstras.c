#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define white 0
#define gray  1
#define black 2

int visited[]={0,0,0,0,0,0,0};

struct h_node{
    int h_id;
    struct h_node* h_next;
    struct h_node* h_prev;
};

struct v_node{
    int v_id;
    struct v_node* v_next;
    struct v_node* v_prev;
    struct h_node* edge;
    int color;
    double weight;
    struct v_node* pred;
    double d;
};


struct pri_queue{
    struct v_node* data;
    struct pri_queue* next;
};


struct pri_queue* getpqnode(struct v_node* v_data);

struct pri_queue* createpriqueue(){
    struct v_node* temp=NULL;
    temp=(struct v_node*)malloc(sizeof(struct v_node));
    if (temp==NULL){
        printf("Error is occured\n");
    }
    memset(temp,0,sizeof(struct v_node));
    return getpqnode(temp);
}

int insertbeg(struct pri_queue* p_head_node,struct v_node* v_data){
    struct pri_queue* newnode=getpqnode(v_data);
    newnode->data=v_data;
    newnode->next=p_head_node->next;
    p_head_node->next=newnode;
    return 1;
}


int isempty(struct pri_queue* p_head_node){
    if (p_head_node->next==NULL){
        return 1;
    }
    return 0;
}


void displaypriqueue(struct pri_queue* p_head_node){
    struct pri_queue* temp=p_head_node->next;
    while (temp!=NULL){
        printf("[ %d ]",temp->data->v_id);
        temp=temp->next;
    }
    printf("\n");
}



int removenode(struct pri_queue* p_head_node,struct v_node* temp1){
}
struct v_node* get_min(struct pri_queue* p_head_node){
    struct pri_queue* temp=p_head_node->next;
    struct v_node* temp1=(struct v_node*)malloc(sizeof(struct v_node));
    int min=INT_MAX;
    while (temp!=NULL){
        if (temp->data->d<min){
            min=temp->data->d;
            temp1=temp->data;
        }
        temp=temp->next;
    }
    removenode(p_head_node,temp1);
    return temp1;
}



struct pri_queue* getpqnode(struct v_node* v_data){
    struct pri_queue* pqnode=NULL;
    pqnode=(struct pri_queue*)malloc(sizeof(struct pri_queue));
    if (pqnode==NULL){
        printf("Error is occured\n");
    }
    memset(pqnode,0,sizeof(struct pri_queue));
    pqnode->data=v_data;
    pqnode->next=NULL;
    return pqnode;
}

struct v_node* creategraph();
int addvertex(struct v_node* g_head_node,int v_data);
int addedge(struct v_node* g_head_node,int s_data,int e_data);
void display(struct v_node* g_head_node);
int remove_vertex(struct v_node* g_head_node,int s_data);
int remove_edge(struct v_node* g_head_node,int s_data,int e_data);
void dijstras(struct v_node* g_head_node,int s_vertex);



struct v_node* v_nodecreate();
int v_insert_beg(struct v_node* v_head_node,int data);
int v_insert_end(struct v_node* v_head_node,int data);
int v_delete_node(struct v_node* v_head_node,int s_data);
struct v_node* v_search(struct v_node* v_head_node,int s_data);
struct v_node* v_getnode(int newdata);
void v_display(struct v_node* v_head_node);



struct h_node* h_nodecreate();
int h_insert_beg(struct h_node* h_head_node,int data);
int h_insert_end(struct h_node* h_head_node,int data);
int h_delete_node(struct h_node* h_head_node,int s_data);
struct h_node* h_search(struct h_node* h_head_node,int s_data);
struct h_node* h_getnode(int newdata);
void h_display(struct h_node* h_head_node);



int main(){
    /*struct v_node* p=v_nodecreate();
    v_insert_beg(p,1);
    v_insert_beg(p,2);
    v_insert_end(p,3);
    struct v_node* p3=v_search(p,1);
    printf("%d\n",p3->v_id);
    v_delete_node(p,1);
    v_delete_node(p,2);
    v_delete_node(p,3);
    v_delete_node(p,4);
    v_display(p);
    struct h_node* p1=h_nodecreate();
    h_insert_beg(p1,1);
    h_insert_beg(p1,2);
    h_insert_end(p1,3);
    struct h_node* p2=h_search(p1,1);
    printf("%d\n",p2->h_id);
    h_delete_node(p1,1);
    h_delete_node(p1,2);
    h_delete_node(p1,3);
    h_delete_node(p1,4);
    h_display(p1);*/
    struct v_node* g=creategraph();
    addvertex(g,1);
    addedge(g,1,2);
    addedge(g,1,3);
    addvertex(g,2);
    addedge(g,2,1);
    addedge(g,2,3);
    addvertex(g,3);
    addedge(g,3,2);
    addedge(g,3,4);
    addvertex(g,4);
    addedge(g,4,2);
    addedge(g,4,3);
    //remove_vertex(g,3);
    //remove_edge(g,1,2);
    display(g);
    struct pri_queue* q=createpriqueue();
    for (int i=0;i<5;i++){
        struct v_node* vernode=NULL;
        vernode=(struct v_node*)malloc(sizeof(struct v_node));
        memset(vernode,0,sizeof(struct v_node));
        vernode->v_id=(i+10)*5;
        insertbeg(q,vernode);
    }
    displaypriqueue(q);
    struct v_node* vnode=get_min(q);
    return 0;
}



struct v_node* creategraph(){
    return v_nodecreate();
}



int addvertex(struct v_node* g,int v_data){
    v_insert_end(g,v_data);
}

int addedge(struct v_node* g,int s_data,int e_data){
    struct v_node* p=g;
    struct v_node* s_node=v_search(p,s_data);
    h_insert_end(s_node->edge,e_data);
}

void display(struct v_node* g){
    struct v_node* p_run=g->v_next;
    while (p_run!=g){
        printf("%d <->",p_run->v_id);
        struct h_node* p_run2=p_run->edge->h_next;
        while (p_run2!=p_run->edge){
            printf("%d ",p_run2->h_id);
            p_run2=p_run2->h_next;
        }
        p_run=p_run->v_next;
        printf("\n");
    }
}



int remove_vertex(struct v_node* g,int s_data){
    struct v_node* p_run=g->v_next;
    while (p_run!=g){
        h_delete_node(p_run->edge,s_data);
        p_run=p_run->v_next;
    }
    struct v_node* s_node=v_search(g,s_data);
    free(s_node->edge);
    v_delete_node(g,s_data);
}

int remove_edge(struct v_node* g,int s_data,int e_data){
    struct v_node* s_node=v_search(g,s_data);
    h_delete_node(s_node->edge,e_data);
}

struct v_node* v_nodecreate(){
    return v_getnode(-1);
}

int v_insert_beg(struct v_node* v_head_node,int data){
    struct v_node* new_node=v_getnode(data);
    new_node->v_next=v_head_node->v_next;
    new_node->v_prev=v_head_node;
    v_head_node->v_next->v_prev=new_node;
    v_head_node->v_next=new_node;
}

int v_insert_end(struct v_node* v_head_node,int data){
    struct v_node* new_node=v_getnode(data);
    new_node->v_next=v_head_node;
    new_node->v_prev=v_head_node->v_prev;
    v_head_node->v_prev->v_next=new_node;
    v_head_node->v_prev=new_node;
}

int v_delete_node(struct v_node* v_head_node,int s_data){
    if (v_head_node->v_next==v_head_node){
        return 0;
    }
    struct v_node* s_node=v_search(v_head_node,s_data);
    if (s_node==NULL){
        return 0;
    }
    s_node->v_prev->v_next=s_node->v_next;
    s_node->v_next->v_prev=s_node->v_prev;
    return 1;
}

struct v_node* v_search(struct v_node* v_head_node,int s_data){
    struct v_node* p_run=v_head_node->v_next;
    while (p_run!=v_head_node){
        if (p_run->v_id==s_data){
            return p_run;
        }
        p_run=p_run->v_next;
    }
    return NULL;
}



void v_display(struct v_node* v_head_node){
    struct v_node* p_run=v_head_node->v_next;
    while (p_run!=v_head_node){
        printf("%d\n",p_run->v_id);
        p_run=p_run->v_next;
    }
}



struct v_node* v_getnode(int newdata){
    struct v_node* p=NULL;
    p=(struct v_node*)malloc(sizeof(struct v_node));
    if (p==NULL){
        printf("error is occured\n");
    }
    memset(p,0,sizeof(struct v_node));
    p->v_id=newdata;
    p->v_next=p;
    p->v_prev=p;
    p->edge=h_nodecreate();
    return p;
}



struct h_node* h_nodecreate(){
    return h_getnode(-1);
}

int h_insert_beg(struct h_node* h_head_node,int data){
    struct h_node* new_node=h_getnode(data);
    new_node->h_next=h_head_node->h_next;
    new_node->h_prev=h_head_node;
    h_head_node->h_next->h_prev=new_node;
    h_head_node->h_next=new_node;
}

int h_insert_end(struct h_node* h_head_node,int data){
    struct h_node* new_node=h_getnode(data);
    new_node->h_next=h_head_node;
    new_node->h_prev=h_head_node->h_prev;
    h_head_node->h_prev->h_next=new_node;
    h_head_node->h_prev=new_node;
}

int h_delete_node(struct h_node* h_head_node,int s_data){
    if (h_head_node->h_next==h_head_node){
        return 0;
    }
    struct h_node* s_node=h_search(h_head_node,s_data);
    if (s_node==NULL){
        return 0;
    }
    s_node->h_prev->h_next=s_node->h_next;
    s_node->h_next->h_prev=s_node->h_prev;
    return 1;
}

struct h_node* h_search(struct h_node* h_head_node,int s_data){
    struct h_node* p_run=h_head_node->h_next;
    while (p_run!=h_head_node){
        if (p_run->h_id==s_data){
            return p_run;
        }
        p_run=p_run->h_next;
    }
    return NULL;
}


void h_display(struct h_node* h_head_node){
    struct h_node* p_run=h_head_node->h_next;
    while (p_run!=h_head_node){
        printf("%d\n",p_run->h_id);
        p_run=p_run->h_next;
    }
}



struct h_node* h_getnode(int newdata){
    struct h_node* p=NULL;
    p=(struct h_node*)malloc(sizeof(struct h_node));
    if (p==NULL){
        printf("error is occured\n");
    }
    memset(p,0,sizeof(struct h_node));
    p->h_id=newdata;
    p->h_next=p;
    p->h_prev=p;
    return p;
}