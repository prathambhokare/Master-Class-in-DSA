#include <stdio.h>
#include <stdlib.h>
#include <string.h>
;

#define white 0
#define gray  1
#define black 2

int visited[]={0,0,0,0,0,0,0};

struct h_node{
    int h_id;
    double weight;
    struct h_node* h_next;
    struct h_node* h_prev;
};


struct v_node{
    int v_id;
    struct v_node* v_next;
    struct v_node* v_prev;
    struct h_node* edge;
    int color;
    struct v_node* pred;
    double d;
};



struct queue{
    struct v_node* data;
    struct queue* next;
};


struct queue* queue_getnode(struct v_node* newdata);

struct queue* createqueue(){
    struct v_node* p=NULL;
    p=(struct v_node*)malloc(sizeof(struct v_node));
    memset(p,0,sizeof(struct v_node));
    p->v_id=-1;
    return queue_getnode(p);
}


struct queue* queue_getnode(struct v_node* newdata){
    struct queue* p=NULL;
    p=(struct queue*)malloc(sizeof(struct queue));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct queue));
    p->data=newdata;
    p->next=NULL;
    return p;
}

int insertend(struct queue* q,struct v_node* newdata){
    struct queue* newnode=queue_getnode(newdata);
    struct queue* prev=q;
    struct queue* p_run=q->next;
    while (p_run!=NULL){
        prev=p_run;
        p_run=p_run->next;
    }
    newnode->next=NULL;
    prev->next=newnode;
}


int isempty(struct queue* q){
    if (q->next==NULL){
        return 1;
    }
    return 0;
}




struct v_node* removeminnode(struct queue* q){
    if (isempty(q)){
        return NULL;
    }
    struct queue* r_node=q->next;
    struct v_node* temp=NULL;
    temp=(struct v_node*)malloc(sizeof(struct v_node));
    int min=69696;
    while (r_node!=NULL){
        if (r_node->data->v_id<min){
            min=r_node->data->v_id;
            temp=r_node->data;
        }
        r_node=r_node->next;
    }
    return temp;
}



struct v_node* creategraph();
int addvertex(struct v_node* g_head_node,int v_data);
int addedge(struct v_node* g_head_node,int s_data,int e_data);
void display(struct v_node* g_head_node);
int remove_vertex(struct v_node* g_head_node,int s_data);
int remove_edge(struct v_node* g_head_node,int s_data,int e_data);
void dfs(struct v_node* p_head_node);
void dfs_visit(struct v_node* p_head_node,struct v_node* u);
void bfs(struct v_node* p_head_node,int source);
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


void dijiktras(struct v_node* v_head_node,int s_node);
void relax(struct v_node* s,struct v_node* e);


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
    addedge(g,1,2,2.0);
    addedge(g,1,3,3.0);
    addvertex(g,2);
    addedge(g,2,1,1.0);
    addedge(g,2,3,4.0);
    addvertex(g,3);
    addedge(g,3,2,2.0);
    addedge(g,3,4,2.0);
    addvertex(g,4);
    addedge(g,4,2,3.0);
    addedge(g,4,3,4.0);
    //remove_vertex(g,3);
    //remove_edge(g,1,2);
    display(g);
    //dfs(g);
    struct queue* q=createqueue();
    for (int i=0;i<5;i++){
        struct v_node* vernode=NULL;
        vernode=(struct v_node*)malloc(sizeof(struct v_node));
        memset(vernode,0,sizeof(struct v_node));
        vernode->v_id=5-i;
        insertend(q,vernode);
    }
    printf("%d\n",q->next->next->data->v_id);
    struct v_node* temp=removeminnode(q);
    printf("the remove minimum is node data is %d\n",temp->v_id);
    printf("%d\n",q->next->next->data->v_id);
    //bfs(g,2);
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

void dfs(struct v_node* p_head_node){
    struct v_node* p=p_head_node->v_next;
    while (p!=p_head_node){
        if (visited[p->v_id]==white){
        //if (p->v_color==white){
            printf("vertex for dfs is %d\n",p->v_id);
            dfs_visit(p_head_node,p);
        }
        p=p->v_next;
    }
}

void dfs_visit(struct v_node* p_head_node,struct v_node* u){
    visited[u->v_id]=gray;
    //u->v_color=gray;
    printf("%d\n",u->v_id);
    struct h_node* p_run1=u->edge->h_next;
    while (p_run1!=u->edge){
        if (visited[p_run1->h_id]==white){
        //if (p_run1->color==white){
            struct v_node* p_run=p_head_node->v_next;
            while (p_run!=p_head_node){
                if (p_run->v_id=p_run1->h_id){
                    break;
                }
                p_run=p_run->v_next;
            }
            dfs_visit(p_head_node,p_run);
        }
        p_run1=p_run1->h_next;
    }
    visited[u->v_id]=black;
    //u->v_color=black;
}



void bfs(struct v_node* p_head_node,int source){
    /*struct queue* q=createqueue();
    visited[source]=1;
    struct v_node* s_node=v_search(p_head_node,source);
    insertend(q,s_node);
    int k=0;
    while (!isempty(q)){
        //struct v_node* temp=removebeg(q);
       // printf("the remove node data is %d\n",temp->v_id);
        struct h_node* r_run=temp->edge->h_next;
        //printf("the horizontal node data is %d\n",r_run->h_id);
        while (r_run!=temp->edge){
           // printf("the horizontally visited data is %d\n",r_run->h_id);
            if (visited[r_run->h_id]==0){
                //printf("true for %d and before color is %d\n",r_run->h_id,visited[r_run->h_id]);
                visited[r_run->h_id]=1;
                //printf("true for %d and after color is %d\n",r_run->h_id,visited[r_run->h_id]);
                struct v_node* snode=v_search(p_head_node,r_run->h_id);
                insertend(q,snode);
            }
            r_run=r_run->h_next;
        }
        visited[temp->v_id]=2;
        //break;
    }*/
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


void dijiktras(struct v_node* v_head_node,int source_node){
    struct v_node* temp=v_head_node->v_next;
    struct queue* q=createqueue();
    while (temp!=v_head_node){
        temp->pred=NULL;
        temp->d=696969;
        temp=temp->v_next;
        insertend(q,temp);
    }
    struct v_node* s_node=v_search(v_head_node,source_node);
    s_node->d=0;
    while (!isempty(q)){
        struct v_node* minnode=removeminnode(q);
        struct h_node* temp1=minnode->edge->h_next;
        while (temp1!=minnode->edge){
            struct v_node* hvnode=v_search(v_head_node,temp1->h_id);
            relax(minnode,hvnode);
            temp1=temp1->h_next;
        }
    }
}



void relax(struct v_node* s,struct v_node* e){
    if (e->d>(s->d+e->weight)){
        e->d=s->d+e->weight;
        e->pred=s;
    }
}