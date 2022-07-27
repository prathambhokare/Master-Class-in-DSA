#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct vnode{
    int vid;
    int color;
    int d;
    struct vnode* prev;
    struct vnode* next;
    struct hnode* h_node_head;
};

struct pri_queue{
    struct vnode* pvhead;
    struct pri_queue* next;
    struct pri_queue* prev;
};




/*priority queue*/
struct pri_queue* createqueue();
int insert_beg(struct pri_queue* q,struct vnode* data);
struct vnode* mindelete(struct pri_queue* q);
struct pri_queue* searchqnode(struct pri_queue* q,struct vnode* s_data);
struct pri_queue* getqnode(struct vnode* data);
void displayq(struct pri_queue* q);


int main(){
    struct pri_queue* p=createqueue();
    printf("%d\n",p->pvhead->d);
    for (int i=0;i<3;i++){
        struct vnode* p1=NULL;
        p1=(struct vnode*)malloc(sizeof(struct vnode));
        if (p1==NULL){
            printf("Error is occured\n");
        }
        memset(p1,0,sizeof(struct vnode));
        p1->d=(i+1)*10;
        insert_beg(p,p1);
    }
    printf("%d\n",p->next->pvhead->d);
    displayq(p);
    return 0;
}



struct pri_queue* createqueue(){
    struct vnode* p=NULL;
    p=(struct vnode*)malloc(sizeof(struct vnode));
    return getqnode(p);
}



int insert_beg(struct pri_queue* q,struct vnode* data){
    struct pri_queue* newnode=getqnode(data);
    newnode->next=q->next;
    newnode->prev=q;
    q->next->prev=newnode;
    q->prev=newnode;
    return 1;
}


struct vnode* mindelete(struct pri_queue* q){
    struct pri_queue* p_run=q->next->next;
    struct pri_queue* min=q->next;
    while (p_run!=q){
        if (p_run->pvhead->d<min->pvhead->d){
            min=p_run;
        }
        p_run=p_run->next;
    }
    return min->pvhead;
}

struct pri_queue* searchqnode(struct pri_queue* q,struct vnode* s_data){
    struct pri_queue* p_run=q->next;
    while (p_run!=q){
        if (p_run->pvhead==s_data){
            return p_run;
        }
    }
    return NULL;
}

struct pri_queue* getqnode(struct vnode* data){
    struct pri_queue* newnode=(struct pri_queue*)malloc(sizeof(struct pri_queue));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct pri_queue));
    newnode->pvhead=data;
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}

void displayq(struct pri_queue* q){
    struct pri_queue* p_run=q->next;
    while (p_run!=q){
        printf("[ %d ]",p_run->pvhead->d);
        p_run=p_run->next;
    }
    printf("\n");
}