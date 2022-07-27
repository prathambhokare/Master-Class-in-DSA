#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define white 0
#define gray  1
#define black 2


struct hnode{
    int v_idh;
    int w;
    struct hnode* next;
    struct hnode* prev;
};


struct vnode{
    int vid;
    int color;
    int d;
    struct vnode* prev;
    struct vnode* next;
    struct hnode* h_node_head;
};

struct graph{
    struct vnode* g_head;
    int nr_vertex;
};

struct queue{
    struct vnode* v_vertex;
    struct queue* next;
    struct queue* prev;
};


/*1 horiaontal list mangement*/
struct hnode* createhlist();
int insert_end_h(struct hnode* h_head_node,int data,int w);
struct hnode* deletehnode(struct hnode* h_head_node,int s_data);
struct hnode* searchhnode(struct hnode* h_head_node,int s_data);
struct hnode* gethnode(int data,int w);
void displayh(struct hnode* h_head_node);



/*2 vertical list management*/
struct vnode* createvlist();
int insert_end_v(struct vnode* h_head_node,int data);
struct vnode* deletevnode(struct vnode* h_head_node,int s_data);
struct vnode* searchvnode(struct vnode* h_head_node,int s_data);
struct vnode* getvnode(int data);
void displayv(struct vnode* h_head_node);

/*3 graph management*/
struct graph* creategraph();
int addvertex(struct graph* g,int v_id);
int addedge(struct graph* g,int start_vertex,int end_vertex,int w);
int removevertex(struct graph* g,int v_id);
int removeedge(struct graph* g,int start_vertex,int end_vertex);
void dfs(struct graph* g);
void dfs_visit(struct graph* g,struct vnode* vertex);
void bfs(struct graph* g,struct vnode* vertex);
void displayg(struct graph* g);


/*4 queue management*/
struct queue* createqueue();
int insert_beg(struct queue* q,struct vnode* data);
struct queue* deleteqbeg(struct queue* q);
struct queue* searchqnode(struct queue* q,struct vnode* s_data);
struct queue* getqnode(struct vnode* data);
void displayq(struct queue* q);


int main(){
    struct vnode* p1=createvlist();
    insert_end_v(p1,1);
    insert_end_v(p1,2);
    insert_end_v(p1,3);
    insert_end_v(p1,4);
    displayv(p1);
    deletevnode(p1,5);
    displayv(p1);
    struct graph* g=creategraph();
    addvertex(g,1);
    addvertex(g,2);
    addvertex(g,3);
    addvertex(g,4);
    addedge(g,1,2,4);
    addedge(g,2,3,5);
    addedge(g,2,4,5);
    removevertex(g,3);
    removeedge(g,1,2);
    displayg(g);
    dfs(g);
    /*struct queue* q=createqueue();
    insert_beg(q,p1);
    deleteqbeg(q);
    displayq(q);*/
    bfs(g,g->g_head->next);
    return 0;
}


/*1 horiaontal list mangement*/
struct hnode* createhlist(){
    return gethnode(-1,-1);
}

int insert_end_h(struct hnode* h_head_node,int data,int w){
    struct hnode* h_point=h_head_node;
    struct hnode* newnode=gethnode(data,w);
    newnode->prev=h_point->prev;
    newnode->next=h_point;
    h_point->prev->next=newnode;
    h_point->prev=newnode;
}


struct hnode* deletehnode(struct hnode* h_head_node,int s_data){
    struct hnode* h_point=h_head_node;
    struct hnode* s_node=searchhnode(h_head_node,s_data);
    struct hnode* d_node=s_node;
    if  (s_node==NULL){
        printf("list is empty\n");
    }
    else{
        s_node->next->prev=s_node->prev;
        s_node->prev->next=s_node->next;
    }
    free(s_node);
    s_node=NULL;
    return d_node;
}

struct hnode* searchhnode(struct hnode* h_head_node,int s_data){
    if (h_head_node->next==h_head_node && h_head_node->prev==h_head_node){
        printf("List is empty\n");
        return NULL;
    }
    else{
        struct hnode* p_run=h_head_node->next;
        while (p_run!=h_head_node){
            if (p_run->v_idh==s_data){
                return p_run;
            }
            p_run=p_run->next;
        }
    }
    return NULL;
}


struct hnode* gethnode(int data,int w){
    struct hnode* temp= NULL;
    temp=(struct hnode*)malloc(sizeof(struct hnode));
    if (temp==NULL){
        printf("Error is occured\n");
    }
    memset(temp,0,sizeof(struct hnode));
    temp->v_idh=data;
    temp->w=w;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}

void displayh(struct hnode* h_head_node){
    struct hnode* p_run=h_head_node->next;
    printf("[BEG] <->");
    while (p_run!=h_head_node){
        printf("[ %d ]<->",p_run->v_idh);
        p_run=p_run->next;
    }
    printf(" [END]\n");
}




/*2 vertical list management*/
struct vnode* createvlist(){
    return getvnode(-1);
}

int insert_end_v(struct vnode* h_head_node,int data){
    struct vnode* h_point=h_head_node;
    struct vnode* newnode=getvnode(data);
    newnode->prev=h_point->prev;
    newnode->next=h_point;
    h_point->prev->next=newnode;
    h_point->prev=newnode;
}


struct vnode* deletevnode(struct vnode* h_head_node,int s_data){
    struct vnode* h_point=h_head_node;
    struct vnode* s_node=searchvnode(h_head_node,s_data);
    struct vnode* d_node=s_node;
    if  (s_node==NULL){
        printf("list is empty\n");
    }
    else{
        s_node->next->prev=s_node->prev;
        s_node->prev->next=s_node->next;
    }
    free(s_node);
    s_node=NULL;
    return d_node;
}

struct vnode* searchvnode(struct vnode* h_head_node,int s_data){
    if (h_head_node->next==h_head_node && h_head_node->prev==h_head_node){
        printf("List is empty\n");
        return NULL;
    }
    else{
        struct vnode* p_run=h_head_node->next;
        while (p_run!=h_head_node){
            if (p_run->vid==s_data){
                return p_run;
            }
            p_run=p_run->next;
        }
    }
    return NULL;
}


struct vnode* getvnode(int data){
    struct vnode* temp= NULL;
    temp=(struct vnode*)malloc(sizeof(struct vnode));
    if (temp==NULL){
        printf("Error is occured\n");
    }
    memset(temp,0,sizeof(struct vnode));
    temp->vid=data;
    temp->color=white;
    temp->d=0;
    temp->next=temp;
    temp->prev=temp;
    temp->h_node_head=NULL;
    return temp;
}


void displayv(struct vnode* h_head_node){
    struct vnode* p_run=h_head_node->next;
    printf("[BEG] <->");
    while (p_run!=h_head_node){
        printf("[ %d ]<->",p_run->vid);
        p_run=p_run->next;
    }
    printf(" [END]\n");
}


/*3 graph management*/
struct graph* creategraph(){
    struct vnode* temp=createvlist();
    struct graph* g_head=NULL;
    g_head=(struct graph*)malloc(sizeof(struct graph));
    if (g_head==NULL){
        printf("Error is occured\n");
    }
    memset(g_head,0,sizeof(struct graph));
    g_head->g_head=temp;
    g_head->nr_vertex=0;
    return g_head;
}


int addvertex(struct graph* g,int v_id){
    /*valiadtion check the vertex is already present or not*/
    insert_end_v(g->g_head,v_id);
    g->nr_vertex++;
}

int addedge(struct graph* g,int start_vertex,int end_vertex,int w){
    struct vnode* s_node=searchvnode(g->g_head,start_vertex);
    if (s_node->h_node_head==NULL){
        struct hnode* h_head=createhlist();
        s_node->h_node_head=h_head;
        insert_end_h(s_node->h_node_head,end_vertex,w);
    }
    else{
        insert_end_h(s_node->h_node_head,end_vertex,w);
    }
}



int removevertex(struct graph* g,int v_id){
    struct vnode* p_run=g->g_head->next;
    while (p_run!=g->g_head){
        if (p_run->h_node_head!=NULL){
            struct hnode* h_run=p_run->h_node_head;
            deletehnode(h_run,v_id);
        }
        p_run=p_run->next;
    }
    deletevnode(g->g_head,v_id);  
}

int removeedge(struct graph* g,int start_vertex,int end_vertex){
    struct vnode* s_node=searchvnode(g->g_head,start_vertex);
    if (s_node->h_node_head!=NULL){
        deletehnode(s_node->h_node_head,end_vertex);
    }
    struct vnode* s_vnode=searchvnode(g->g_head,end_vertex);
    if (s_node->h_node_head!=NULL){
        deletehnode(s_node->h_node_head,start_vertex);
    }
}
void dfs(struct graph* g){
    struct vnode* p_run=g->g_head->next;
    while (p_run!=g->g_head){
        //p_run->color=white;
        if (p_run->color==white){
            dfs_visit(g,p_run);
        }
        p_run=p_run->next;
    }
}
void dfs_visit(struct graph* g,struct vnode* vertex){
    vertex->color=gray;
    printf("%d ",vertex->vid);
    if (vertex->h_node_head!=NULL){
        struct hnode* h_run=vertex->h_node_head->next;
        while (h_run!=vertex->h_node_head){
            struct vnode* v_node=searchvnode(g->g_head,h_run->v_idh);
            dfs_visit(g,v_node);
            h_run=h_run->next;
        }
    }
    vertex->color=black;
}
void bfs(struct graph* g,struct vnode* vertex){
    vertex->color=gray;
    struct queue* q=createqueue();
    insert_beg(q,vertex);
    while (q->next!=q && q->prev!=q){
        struct queue* qdelete=deleteqbeg(q);
        struct vnode* v_node=qdelete->v_vertex;
        printf("%d ",v_node->vid);
        if (v_node->h_node_head!=NULL){
            struct hnode* h_run=v_node->h_node_head->next;
            while (h_run!=v_node->h_node_head){
                struct vnode* vertexnode=searchvnode(g->g_head,h_run->v_idh);
                if (vertexnode->color==white){
                    vertexnode->color=gray;
                    insert_beg(q,vertexnode);
                }
            }
            v_node->color=black;
        }
    }
}

void displayg(struct graph* g){
    struct vnode* p_run=g->g_head->next;
    while (p_run!=g->g_head){
        printf("%d <->",p_run->vid);
        if (p_run->h_node_head!=NULL){
            struct hnode* h_run=p_run->h_node_head->next;
            while (h_run!=p_run->h_node_head){
                printf(" %d ",h_run->v_idh);
                h_run=h_run->next;
            }
        }
        printf("\n");
        p_run=p_run->next;
    }
}


/*4 queue management*/
struct queue* createqueue(){
    struct vnode* temp=getvnode(-1); 
    return getqnode(temp);
}
int insert_beg(struct queue* q,struct vnode* data){
    struct queue* newnode=getqnode(data);
    newnode->next=q->next;
    newnode->prev=q;
    q->next->prev=newnode;
    q->next=newnode;
}
struct queue* deleteqbeg(struct queue* q){
    struct queue* temp=q->next;
    struct queue* p_run=temp;
    temp->next->prev=q;
    q->next=temp->next;
    free(temp);
    temp=NULL;
    return p_run;
}
struct queue* searchqnode(struct queue* q,struct vnode* s_data){
    struct queue* p_run=q->next;
    if (q->next==q && q->prev==q){
        return NULL;
    }
    while (p_run!=q){
        if (p_run->v_vertex==s_data){
            return p_run;
        }
    }
    return NULL;
}
struct queue* getqnode(struct vnode* data){
    struct queue* newnode=NULL;
    newnode=(struct queue*)malloc(sizeof(struct queue));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct queue));
    newnode->v_vertex=data;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}
void displayq(struct queue* q){
    struct queue* p_run=q->next;
    while (p_run!=q){
        printf("%d ",p_run->v_vertex->vid);
        p_run=p_run->next;
    }
}