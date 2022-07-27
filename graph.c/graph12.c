#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct v_node{
    int v_id;
    int d;
    int pred;
    struct h_node* h_head_node;
    struct v_node* next;
    struct v_node* prev;
};


struct h_node{
    int h_id;
    int weight;
    struct h_node* next;
    struct h_node* prev;
};


struct graph{
    struct v_node* g_head_node;
    int n_vertices;
    int n_edges;
};



/*1.vertical list management*/
struct h_node* createhlist();
int insert_hend(struct h_node* h_head_node,int h_id,int weight);
int remove_hnode(struct h_node* h_head_node,int h_id);
struct h_node* searchhnode(struct h_node* h_head_node,int h_id);
void displayhnode(struct h_node* h_node_head);
struct h_node* gethnode(int h_id,int weight);



/*2.horizontal list management*/
struct v_node* createvlist();
int insert_vend(struct v_node* v_head_node,int v_id);
int remove_vnode(struct v_node* v_head_node,int v_id);
struct v_node* searchvnode(struct v_node* v_head_node,int v_id);
void displayvnode(struct v_node* v_node_head);
struct v_node* getvnode(int v_id);



/*3.graph management*/
struct graph* creategraph();
int addvertex(struct graph* g_head_node,int v_id);
int addedge(struct graph* g_head_node,int s,int d,int w);
void displaygraph(struct graph* g_head_node);

int main(){
    /*struct v_node* p=createvlist();
    insert_vend(p,0);
    remove_vnode(p,0);
    insert_vend(p,1);
    displayvnode(p);*/
    struct graph* p=creategraph();
    addvertex(p,0);
    //displaygraph(p);
    return 0;
}




struct graph* creategraph(){
    struct v_node* temp=createvlist();
    struct graph* g_head_node=NULL;
    g_head_node=(struct graph*)malloc(sizeof(struct graph));
    if (g_head_node==NULL){
        printf("Error occured\n");
    }
    memset(g_head_node,0,sizeof(struct graph));
    g_head_node->g_head_node=temp;
    g_head_node->n_edges=0;
    g_head_node->n_vertices=0;
    return g_head_node;
}



int addvertex(struct graph* g_head_node,int v_id){
    insert_vend(g_head_node->g_head_node,v_id);
    g_head_node->n_vertices++;
    return 1;
}

int addedge(struct graph* g_head_node,int s,int d,int w){
    struct v_node* s_node=searchvnode(g_head_node->g_head_node,s);
    if (s_node->h_head_node==NULL){
        struct h_node* h_head_node=createhlist();
        insert_hend(h_head_node,d,w);
    }
    else{
        insert_hend(s_node->h_head_node,d,w);
    }
    struct v_node* s1_node=searchvnode(g_head_node->g_head_node,d);
    if (s1_node->h_head_node==NULL){
        struct h_node* h_head_node=createhlist();
        insert_hend(h_head_node,s,w);
    }
    else{
        insert_hend(s_node->h_head_node,s,w);
    }
    g_head_node->n_edges++;
    return 1;
}


void displaygraph(struct graph* g_head_node){
    struct v_node* temp=g_head_node->g_head_node->next;
    while (temp!=g_head_node->g_head_node){
        printf("%d \n",temp->v_id);
        struct h_node* temp2=temp->h_head_node->next;
        while (temp2!=temp->h_head_node){
            printf(" %d ",temp2->h_id);
            temp2=temp2->next;
        }
        temp=temp->next;
        printf("\n");
    }
}




struct v_node* createvlist(){
    return getvnode(-1);
}

int insert_vend(struct v_node* v_head_node,int v_id){
    struct v_node* temp=v_head_node->next;
    struct v_node* newnode=getvnode(v_id);
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
}


int remove_vnode(struct v_node* v_head_node,int v_id){
    struct v_node* temp=v_head_node->next;
    while (temp!=v_head_node){
        if (temp->v_id==v_id){
            break;
        }
        temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    temp=NULL;
}



struct v_node* searchvnode(struct v_node* v_head_node,int v_id){
    struct v_node* temp=v_head_node->next;
    while (temp!=v_head_node){
        if (temp->v_id==v_id){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;    
}




void displayvnode(struct v_node* v_head_node){
    struct v_node* temp=v_head_node->next;
    while (temp!=v_head_node){
        printf("[ %d ]<->",temp->v_id);
        temp=temp->next;
    }
    printf("\n");
}


struct v_node* getvnode(int v_id){
    struct v_node* newnode=NULL;
    newnode=(struct v_node*)malloc(sizeof(struct v_node));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct v_node));
    newnode->v_id=v_id;
    newnode->h_head_node=NULL;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}

struct h_node* createhlist(){
     return gethnode(-1,0);
}

int insert_hend(struct h_node* h_head_node,int h_id,int weight){
    struct h_node* temp=h_head_node->next;
    struct h_node* newnode=gethnode(h_id,weight);
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
}


int remove_hnode(struct h_node* h_head_node,int h_id){
    struct h_node* temp=h_head_node->next;
    while (temp!=h_head_node){
        if (temp->h_id==h_id){
            break;
        }
        temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    temp=NULL;
}

struct h_node* searchhnode(struct h_node* h_head_node,int h_id){
    struct h_node* temp=h_head_node->next;
    while (temp!=h_head_node){
        if (temp->h_id==h_id){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;  
}


void displayhnode(struct h_node* h_head_node){
    struct h_node* temp=h_head_node->next;
    while (temp!=h_head_node){
        printf("[ %d ]<->",temp->h_id);
        temp=temp->next;
    }
    printf("\n");
}


struct h_node* gethnode(int h_id,int weight){
    struct h_node* newnode=NULL;
    newnode=(struct h_node*)malloc(sizeof(struct h_node));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct h_node));
    newnode->h_id=h_id;
    newnode->weight=weight;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}