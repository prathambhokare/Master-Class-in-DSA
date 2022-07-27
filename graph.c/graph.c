#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define white 0
#define gray  1
#define black 2

int visited[]={0,0,0,0,0,0,0};

struct vertex{
    int v_vertex_id;
    struct vertex* v_next;
    struct vertex* v_prev;
};



struct vertex_list{
    int vl_vertex_id;
    struct vertex* nextvertex;
    struct vertex_list* vl_next;
    struct vertex_list* vl_prev;
};


struct node{
    struct vertex_list* vertex_l;
    struct node* next;
    struct node* prev;
};

int empty(struct node* p_head_node){
    if (p_head_node->next==NULL){
        return 1;
    }
    return 0;
}






struct node* getnode2(struct vertex_list* new_node){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->vertex_l=new_node;
    p->next=NULL;
    return p;
}



struct node* createlist(){
    struct vertex_list* p=NULL;
    p->vl_vertex_id=-1;
    p->vl_next=NULL;
    p->vl_prev=NULL;
    p->nextvertex=NULL;
    return getnode2(p);
}


int enqueue(struct node* p_head_node,struct vertex_list* newdata){
    struct node* new_node=NULL;
    new_node=getnode2(newdata);  
    struct node* p_run=p_head_node;
    while (p_run->next!=NULL){
        p_run=p_run->next;
    }
    p_run->next=new_node;
    new_node->next=NULL;
    return 1;
}



struct vertex_list* dequeue(struct node* p_head_node){
    struct vertex_list* data=NULL;
    struct node* temp=p_head_node->next;
    data=p_head_node->next->vertex_l;
    p_head_node->next=temp->next;
    free(temp);
    temp=NULL;
    return data;
}

/*void showlist(struct node* p_head_node){
    struct node* p_run=NULL;
    p_run=p_head_node->next;
    printf("[BEG]<->");
    while (p_run!=NULL){
        printf("[%d]<->",p_run->data);
        p_run=p_run->next;
    }
    printf("[END]\n");
}*/

struct vertex_list* creategraph();
int addvertex(struct vertex_list* p_head_node,int vertex_name);
int addedge(struct vertex_list* p_head_node,int sartvertex_name,int endvertex_name);
int removevertex(struct vertex_list* p_head_node,int vertex_name);
int removedge(struct vertex_list* p_head_node,int startvertex_name,int endvertex_name);
void display(struct vertex_list* p_head_node,const char* msg);


void dfs(struct vertex_list* p_head_node);
void dfs_visit(struct vertex_list* p_head_node,struct vertex_list* u);
void bfs(struct vertex_list* p_head_node,struct vertex_list* s_vertex);

/*vertex*/
struct vertex* createvertex1();
int insert_end(struct vertex* p_head_node,int newdata);
int removenode(struct vertex* p_head_node,int s_data);
void display1(struct vertex* p_head_node);




struct vertex* getnode(int newdata);
void generic_insert(struct vertex* beg,struct vertex* mid,struct vertex* end);
void generic_delete(struct vertex* beg,struct vertex* mid,struct vertex* end);
struct vertex* serachvnode(struct vertex* p_head_node,int s_data);


/*vertex_list*/
struct vertex_list* v_createlist_vertex1();
int v_insert_end(struct vertex_list* p_head_node,int newdata);
int v_removenode(struct vertex_list* p_head_node,int s_data);



struct vertex_list* v_getnode(int newdata);
void v_generic_insert(struct vertex_list* beg,struct vertex_list* mid,struct vertex_list* end);
void v_generic_delete(struct vertex_list* beg,struct vertex_list* mid,struct vertex_list* end);
struct vertex_list* v_serachvnode(struct vertex_list* p_head_node,int s_data);



void* xmalloc(int nr_bytes);
int main(){
    struct vertex* p=createvertex1();
    printf("data is %d\n",p->v_vertex_id);
    insert_end(p,1);
    insert_end(p,2);
    insert_end(p,3);
    insert_end(p,4);
    printf("data is %d\n",p->v_prev->v_vertex_id);
    removenode(p,4);
    printf("data is %d\n",p->v_prev->v_vertex_id);
    display1(p);
    struct vertex_list* p1=v_createlist_vertex1();
    printf("data is %d\n",p1->vl_vertex_id);
    v_insert_end(p1,1);
    v_insert_end(p1,2);
    v_insert_end(p1,3);
    v_insert_end(p1,4);
    printf("data is %d\n",p1->vl_prev->vl_vertex_id);
    v_removenode(p1,4);
    printf("data is %d\n",p1->vl_prev->vl_vertex_id);
    struct vertex_list* p2=creategraph();
    addvertex(p2,0);
    addvertex(p2,1);
    addvertex(p2,2);
    addvertex(p2,3);
    addvertex(p2,4);
    addvertex(p2,5);
    addvertex(p2,6);
    addedge(p2,0,1);
    addedge(p2,0,2);
    addedge(p2,0,3);
    addedge(p2,1,0);
    addedge(p2,1,3);
    addedge(p2,1,6);
    addedge(p2,2,1);
    addedge(p2,2,3);
    addedge(p2,2,4);
    addedge(p2,3,0);
    addedge(p2,3,1);
    addedge(p2,3,2);
    addedge(p2,3,4);
    addedge(p2,3,5);
    addedge(p2,3,6);
    addedge(p2,4,2);
    addedge(p2,4,3);
    addedge(p2,4,5);
    addedge(p2,5,3);
    addedge(p2,5,4);
    addedge(p2,5,6);
    addedge(p2,6,1);
    addedge(p2,6,3);
    addedge(p2,6,5);
    printf("%d\n",p2->vl_next->nextvertex->v_next->v_next->v_vertex_id);
    display(p2,"msg");
    dfs(p2);
    //bfs(p2,0);
    return 0;
}


struct vertex_list* creategraph(){
    return v_createlist_vertex1();
}

void dfs(struct vertex_list* p_head_node){
    struct vertex_list* p=p_head_node->vl_next;
    while (p!=p_head_node){
        if (visited[p->vl_vertex_id]==white){
        //if (p->v_color==white){
            printf("vertex for dfs is %d\n",p->vl_vertex_id);
            dfs_visit(p_head_node,p);
        }
        p=p->vl_next;
    }
}

void dfs_visit(struct vertex_list* p_head_node,struct vertex_list* u){
    visited[u->vl_vertex_id]=gray;
    //u->v_color=gray;
    printf("%d\n",u->vl_vertex_id);
    struct vertex* p_run1=u->nextvertex->v_next;
    while (p_run1!=u->nextvertex){
        if (visited[p_run1->v_vertex_id]==white){
        //if (p_run1->color==white){
            struct vertex_list* p_run=p_head_node->vl_next;
            while (p_run!=p_head_node){
                if (p_run->vl_vertex_id==p_run1->v_vertex_id){
                    break;
                }
                p_run=p_run->vl_next;
            }
            dfs_visit(p_head_node,p_run);
        }
        p_run1=p_run1->v_next;
    }
    visited[u->vl_vertex_id]=black;
    //u->v_color=black;
}


void bfs(struct vertex_list* p_head_node,struct vertex_list* s_vertex){
    visited[s_vertex->vl_vertex_id]=gray;
    struct node* q=createlist();
    enqueue(q,s_vertex);
    while (!empty(q)){
        struct vertex_list* p=dequeue(q);
        struct vertex* p_run=p->nextvertex->v_next;
        while (p_run!=p->nextvertex){
            if (visited[p_run->v_vertex_id]==white){
                visited[p_run->v_vertex_id]=gray;
                struct vertex_list* p_run1=p_head_node->vl_next;
                while (p_run1!=p_head_node){
                    if (p_run1->vl_vertex_id==p_run->v_vertex_id){
                        break;
                    }
                    p_run1=p_run1->vl_next;
                }
                enqueue(q,p_run1);
            }
            visited[p_run->v_vertex_id]=black;
        }
    }
}

int addvertex(struct vertex_list* p_head_node,int vertex_name){
    v_insert_end(p_head_node,vertex_name);
}

int addedge(struct vertex_list* p_head_node,int startvertex_name,int endvertex_name){
    struct vertex_list* p_run=p_head_node->vl_next;
    while (p_run!=p_head_node){
        if (p_run->vl_vertex_id==startvertex_name){
            if (p_run->nextvertex==NULL){
                struct vertex* p=createvertex1();
                p_run->nextvertex=p;
                insert_end(p,endvertex_name);  
            }
            else{
                struct vertex* p=p_run->nextvertex;
                printf("next vertex data is %d\n",p->v_vertex_id);
                insert_end(p,endvertex_name);
            }
            break;
        }
        p_run=p_run->vl_next;
    }
}


int removevertex(struct vertex_list* p_head_node,int vertex_name){
    return v_removenode(p_head_node,vertex_name);
}

void display(struct vertex_list* p_head_node,const char* msg){
    struct vertex_list* p_run=p_head_node->vl_next;
    while (p_run!=p_head_node){
        printf("%d <->",p_run->vl_vertex_id); 
        if (p_run->nextvertex!=NULL){
            display1(p_run->nextvertex);
        }
        printf("\n");
        p_run=p_run->vl_next;
    }
}

/*vertex*/
struct vertex* createvertex1(){
    struct vertex* p=getnode(-1);
    p->v_vertex_id=-1;
    p->v_next=p;
    p->v_prev=p;
    return p;
}

int insert_end(struct vertex* p_head_node,int newdata){
    struct vertex* p_run=p_head_node->v_next;
    generic_insert(p_head_node,getnode(newdata),p_head_node->v_prev);
}


int removenode(struct vertex* p_head_node,int s_data){
    if (p_head_node->v_next==p_head_node){
        printf("list is empty\n");
        return 0;
    }
    struct vertex* p_run=NULL;
    p_run=p_head_node->v_next;
    while (p_run!=p_head_node){
        if  (p_run->v_vertex_id==s_data){
            p_run->v_prev->v_next=p_run->v_next;
            p_run->v_next->v_prev=p_run->v_prev;
            free(p_run);
            p_run=NULL;
            break;
        }
        p_run=p_run->v_next;
    }
}


void display1(struct vertex* p_head_node){
    struct vertex* p_run=p_head_node->v_next;
    while (p_run!=p_head_node){
        printf(" %d ",p_run->v_vertex_id);
        p_run=p_run->v_next;
    }
}

struct vertex* getnode(int newdata){
    struct vertex* p=NULL;
    p=(struct vertex*)xmalloc(sizeof(struct vertex));
    p->v_vertex_id=newdata;
    p->v_next=NULL;
    p->v_prev=NULL;
    return p;
}

void generic_insert(struct vertex* beg,struct vertex* mid,struct vertex* end){
    mid->v_next=beg;
    mid->v_prev=end;
    end->v_next=mid;
    beg->v_prev=mid;
}


void generic_delete(struct vertex* beg,struct vertex* mid,struct vertex* end){
    beg->v_next=end;
    end->v_prev=beg;
    free(mid);
    mid=NULL;
}


struct vertex* serachvnode(struct vertex* p_head_node,int s_data){
    struct vertex* p_run=p_head_node->v_next;
    while (p_run!=NULL){
        if (p_run->v_vertex_id==s_data){
            return p_run;
        }
    }
    return NULL;
}


/*vertex_list*/
struct vertex_list* v_createlist_vertex1(){
    struct vertex_list* p=v_getnode(-1);
    p->vl_next=p;
    p->vl_prev=p;
    p->vl_vertex_id=-1;
    p->nextvertex=NULL;
    return p;
}




int v_insert_end(struct vertex_list* p_head_node,int newdata){
    struct vertex_list* p_run=p_head_node->vl_next;
    v_generic_insert(p_head_node,v_getnode(newdata),p_head_node->vl_prev);
}


int v_removenode(struct vertex_list* p_head_node,int s_data){
    if (p_head_node->vl_next==p_head_node){
        printf("list is empty\n");
        return 0;
    }
   struct vertex_list* p_run=NULL;
    p_run=p_head_node->vl_next;
    while (p_run!=p_head_node){
        if  (p_run->vl_vertex_id==s_data){
            break;
        }
        p_run=p_run->vl_next;
    }
    p_run->vl_prev->vl_next=p_run->vl_next;
    p_run->vl_next->vl_prev=p_run->vl_prev;
    free(p_run);
    p_run=NULL;
}


struct vertex_list* v_getnode(int newdata){
    struct vertex_list* p=NULL;
    p=(struct vertex_list*)xmalloc(sizeof(struct vertex_list));
    p->vl_vertex_id=newdata;
    p->vl_next=NULL;
    p->vl_prev=NULL;
    p->nextvertex=NULL;   
    return p;
}



void v_generic_insert(struct vertex_list* beg,struct vertex_list* mid,struct vertex_list* end){
    mid->vl_next=beg;
    mid->vl_prev=end;
    end->vl_next=mid;
    beg->vl_prev=mid;
}

void v_generic_delete(struct vertex_list* beg,struct vertex_list* mid,struct vertex_list* end){
    mid->vl_prev->vl_next=mid->vl_next;
    mid->vl_next->vl_prev=mid->vl_prev;
    free(mid);
    mid=NULL;
}


struct vertex_list* v_serachvnode(struct vertex_list* p_head_node,int s_data){
    struct vertex_list* p_run=p_head_node->vl_next;
    while (p_run!=NULL){
        if (p_run->vl_vertex_id==s_data){
            return p_run;
        }
    }
    return NULL;
}



void* xmalloc(int nr_bytes){
    void* p=NULL;
    p=malloc(nr_bytes);
    if (p==NULL){
        printf("error is occured\n");
        exit(0);
    }
    memset(p,0,nr_bytes);
    return p;
}