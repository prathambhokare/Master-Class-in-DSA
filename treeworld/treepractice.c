#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int data_t;
typedef struct node node_t;
typedef struct bst bst_t;
typedef int status;




struct node{
    data_t data;
    node_t* left;
    node_t* right;
};

struct bst{
    node_t* bsthead;
    data_t nr_node;
};


bst_t* createtree();

status insert(bst_t* bst,data_t data);
node_t* search_r(node_t* bst_head_node,data_t data);
status deletenode(bst_t* bst,data_t data);



node_t* max(node_t* bst);
node_t* min(node_t* bst);


void inorder(node_t* bst_head_node);

node_t* getnode(data_t data);

int main(){
    bst_t* p=createtree();
    insert(p,10);
    insert(p,20);
    insert(p,5);
    insert(p,30);
    insert(p,15);
    inorder(p->bsthead);
    node_t* s_node=(node_t*)malloc(sizeof(node_t));
    s_node=search_r(p->bsthead,10);
    printf("%d",s_node->data);
    node_t* m=(node_t*)malloc(sizeof(node_t));
    m=max(p->bsthead);
    printf("maximum value is %d",m->data);
    node_t* mi=(node_t*)malloc(sizeof(node_t));
    mi=min(p->bsthead);
    printf("minimum value is %d",mi->data);
    deletenode(p,10);
    inorder(p->bsthead);
    return 0;
}





bst_t* createtree(){
    bst_t* tnode=(bst_t*)malloc(sizeof(bst_t));
    if (tnode==NULL){
        printf("Error is occured\n");
    }
    memset(tnode,0,sizeof(tnode));
    tnode->bsthead=NULL;
    tnode->nr_node=0;
    return tnode;
}






status insert(bst_t* bst,data_t data){
    bst_t* temp=bst;
    if (temp->bsthead==NULL){
        temp->bsthead=getnode(data);
    }
    else{
        node_t* temp1=bst->bsthead;
        while (1){
        if (temp1->data<data){
            if (temp1->right==NULL){
                temp1->right=getnode(data);
                break;
            }
            else{
                temp1=temp1->right;
            }
        }
        else{
            if (temp1->left==NULL){
                temp1->left=getnode(data);
                break;
            }
            else{
                temp1=temp1->left;
            }
        }
    }
    }
}





node_t* search_r(node_t* bst_head_node,data_t data){
    if (bst_head_node==NULL && bst_head_node->right==NULL){
        return NULL;
    }
    else if (bst_head_node->data==data){
        return bst_head_node;
    }
    else{
        if (bst_head_node->data>data){
            search_r(bst_head_node=bst_head_node->right,data);
        }
        else{
            search_r(bst_head_node=bst_head_node->left,data);
        }
    }
}


status deletenode(bst_t* bst,data_t data){
    node_t* s_node=(node_t*)malloc(sizeof(node_t));
    node_t* prev=(node_t*)malloc(sizeof(node_t));
    prev=NULL;
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    temp=bst->bsthead;
    while (1)
    {
        if (temp->data<data){
            prev=temp;
            temp=temp->right;
        }
        else if (temp->data>data){
            prev=temp;
            temp=temp->left;
        }
        else{
            s_node=temp;
            break;
        }
    }
    if (prev!=NULL){
        printf("prev is found and the value is %d",prev->data);
    }
    if (s_node->left==NULL && s_node->right==NULL){
        if (prev->left==s_node){
            prev->left=NULL;
        }
        else{
            prev->right=NULL;
        }
        free(s_node);
    }
    else if (s_node->left==NULL && s_node->right!=NULL){
        prev->left=s_node->right;
        free(s_node);
    }
    else if (s_node->right==NULL && s_node->left!=NULL){
        prev->right=s_node->left;
        free(s_node);
    }
    else{
        node_t* m=(node_t*)malloc(sizeof(node_t));
        m=max(s_node->left);
        data_t temp=m->data;
        printf("maximum node is %d",m->data);
        deletenode(bst,m->data);
        s_node->data=temp;
        printf("maximum node is %d",temp);
        //deletenode(bst,m->data);
    }
    return 1;
}



node_t* min(node_t* bst){
    node_t* temp=bst;
    while (temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
    
}



node_t* max(node_t* bst){
    node_t* temp=bst;
    while (temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
    
}

void inorder(node_t* bst_head_node){
    if (bst_head_node!=NULL){
        inorder(bst_head_node->left);
        printf("[ %d ] <->",bst_head_node->data);
        inorder(bst_head_node->right);
    }
}



node_t* getnode(data_t data){
    node_t* newnode=NULL;
    newnode=(node_t*)malloc(sizeof(node_t));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(node_t));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
