#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct v{
    int x;
    int y;
    int z;
};

struct vector{
    struct v** vec;
    int size;
};


struct f{
    int v1;
    int v2;
    int v3;
    struct f* next;
    struct f* prev;
};

struct vector* createvector();
int addvertex(struct vector* p1,struct v* vertex);
void show(struct vector* p1);

struct f* createfacelist();
struct f* getnode(int v1,int v2,int v3);
int addend(struct f* f_head_node,int v1,int v2,int v3);
void displaylist(struct f* f_head_node);


int main(){
    /*struct v* p=NULL;
    p=(struct v*)malloc(sizeof(struct v));
    p->x=2;
    p->y=3;
    p->z=4;
    struct vector* p1=NULL;
    p1=(struct vector*)malloc(sizeof(struct vector));
    p1->vec=(struct v**)malloc(sizeof(struct v*));
    p1->vec[0]=(struct v*)malloc(sizeof(struct v));
    p1->vec[0]->x=2;
    p1->vec[0]->y=3;
    p1->vec[0]->z=4;
    printf("%d\n",p1->vec[0]->x);*/
    struct vector* p=createvector();
    struct v* p1=NULL;
    p1=(struct v*)malloc(sizeof(struct v));
    p1->x=2;
    p1->y=3;
    p1->z=4;
    addvertex(p,p1);
    addvertex(p,p1);
    /*printf("%d\n",p->vec[1]->z);*/
    show(p);
    struct f* p4=NULL;
    p4=(struct f*)malloc(sizeof(struct f));
    p4->v1=0;
    p4->v2=1;
    p4->v3=1;
    struct f* p6=createfacelist();
    addend(p6,0,1,1);
    printf("the value is %d",p6->next->v1);
    printf("%d\n",p->vec[p6->next->v1]->x);
    return 0;
}



struct vector* createvector(){
    struct vector* p=NULL;
    p=(struct vector*)malloc(sizeof(struct vector));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct vector));
    p->vec=NULL;
    p->size=0;
}


int addvertex(struct vector* p1,struct v* ve){
    p1->vec=(struct v**)realloc(p1->vec,(p1->size=p1->size+1)*sizeof(struct v*));
    if (p1->vec==NULL){
        printf("Error is occured\n");
    }
    int index=p1->size-1;
    p1->vec[index]=(struct v*)malloc(sizeof(struct v));
    p1->vec[index]->x=ve->x;
    p1->vec[index]->y=ve->y;
    p1->vec[index]->z=ve->z;
    printf("the value of size is %d\n",p1->size);
    /*p1->vec[0]->x=ve->x;
    p1->vec[p1->size-1]->x=ve->x;*/
}




void show(struct vector* p1){
    for (int i=0;i<p1->size;i++){
         printf("%d %d %d %d\n",i,p1->vec[i]->x,p1->vec[i]->y,p1->vec[i]->z);
    }
}



struct f* createfacelist(){
    return getnode(-1,-1,-1);
}

struct f* getnode(int v1,int v2,int v3){
    struct f* newnode=NULL;
    newnode=(struct f*)malloc(sizeof(struct f));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    newnode->v1=v1;
    newnode->v2=v2;
    newnode->v3=v3;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}

int addend(struct f* f_head_node,int v1,int v2,int v3){
    struct f* newnode=NULL;
    newnode=(struct f*)malloc(sizeof(struct f));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    newnode->next=f_head_node;
    newnode->prev=f_head_node->prev;
    f_head_node->prev->next=newnode;
    f_head_node->prev=newnode;
}


void displaylist(struct f* f_head_node){
    struct f* p_run=f_head_node->next;
    while (p_run!=f_head_node){
        printf("%d %d %d",p_run->v1,p_run->v2,p_run->v3);
        p_run=p_run->next;
    }
}