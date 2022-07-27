#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};


struct tree{
    struct node* theadnode;
    int n_node;
};


struct tree* createtree();
struct node* getnode(int data);
int insert(struct tree* t_head_node,int data);
struct node* searchnode(struct tree* t_head_node,int s_data);
void preorder(struct node* t_head_node);
void inorder(struct node* t_head_node);
void postorder(struct node* t_head_node);
struct node* inorderpredecessor(struct tree* t_head_node,int s_data);
struct node* inordersuccessor(struct tree* t_head_node,int s_data);
struct node* max(struct tree* t_head_node);
struct node* min(struct tree* t_head_node);
void mirror(struct node* m_node); 


int main(){
    struct tree* t=createtree();
    insert(t,50);
    insert(t,60);
    insert(t,40);
    insert(t,80);
    insert(t,20);
    insert(t,10);
    insert(t,100);
    preorder(t->theadnode);
    printf("\n");
    inorder(t->theadnode);
    printf("\n");
    postorder(t->theadnode);
    printf("\n");
    struct node* p=searchnode(t,30);
    if (p){
        printf("found\n");
    }
    else{
        printf("not found\n");
    }
    struct node* pred=inorderpredecessor(t,10);
    printf("the inorder predecessor is %d\n",pred->data);
    struct node* succ=inordersuccessor(t,10);
    printf("the inorder successor is %d\n",succ->data);
    struct node* ma=max(t);
    printf("the max node is %d\n",ma->data);
    struct node* mi=min(t);
    printf("the min node is %d\n",mi->data);
    mirror(t->theadnode);
    return 0;
}

struct tree* createtree(){
    struct tree* newnode=NULL;
    newnode=(struct tree*)malloc(sizeof(struct tree));
    if (newnode==NULL){
        printf("Error is occured\n");
    }
    memset(newnode,0,sizeof(struct tree));
    newnode->theadnode=NULL;
    newnode->n_node=0;
    return newnode;
}

struct node* getnode(int newdata){
    struct node* p=NULL;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct node));
    p->data=newdata;
    p->left=NULL;
    p->right=NULL;
    p->parent=NULL;
}


int insert(struct tree* t_head_node,int newdata){
    struct node* newnode=getnode(newdata);
    if (t_head_node->theadnode==NULL){
        t_head_node->theadnode=newnode;
        t_head_node->n_node++;
        return 1;
    }
    struct node* temp=t_head_node->theadnode;
    while (1){
        if (temp->data>newdata){
            if (temp->left==NULL){
                temp->left=newnode;
                newnode->parent=temp;
                temp=temp->left;
                t_head_node->n_node++;
                break;
            }
            else{
                temp=temp->left;
            }
        }
        else if (temp->data<newdata){
            if (temp->right==NULL){
                temp->right=newnode;
                newnode->parent=temp;
                temp=temp->right;
                t_head_node->n_node++;
                break;
            }
            else{
                temp=temp->right;
            }
        }
        else{
            printf("duplicate node\n");
        }
    }
    return 1;
    
}


struct node* searchnode(struct tree* t_head_node,int s_data){
    if (t_head_node->theadnode==NULL){
        return NULL;
    }
    struct node* temp=t_head_node->theadnode;
    while (temp!=NULL){
        if (temp->data>s_data){
            temp=temp->left;
        }
        else if (temp->data<s_data){
            temp=temp->right;
        }
        else{
            return temp;
        }
    }
    return NULL;


}


struct node* inorderpredecessor(struct tree* t_head_node,int s_data){
    struct node* snode=searchnode(t_head_node,s_data);
    if (snode->left!=NULL){
        snode=snode->left;
        if (snode->right!=NULL){
            snode=snode->right;
        }
        return snode;
    }
    else{
        struct node* y=snode->parent;
        while (y!=NULL && snode==y->parent){
            snode=y;
            y=snode->parent;
        }
        return y;
    }
}


struct node* inordersuccessor(struct tree* t_head_node,int s_data){
    struct node* snode=searchnode(t_head_node,s_data);
    if (snode->right!=NULL){
        snode=snode->right;
        if (snode->left!=NULL){
            snode=snode->left;
        }
        return snode;
    }
    else{
        struct node* y=snode->parent;
        while (y!=NULL && snode==y->parent){
            snode=y;
            y=snode->parent;
        }
        return y;
    }
}


struct node* max(struct tree* t_head_node){
    struct node* run=t_head_node->theadnode;
    while (run->right!=NULL){
        run=run->right;
    }
    return run;
}

struct node* min(struct tree* t_head_node){
    struct node* run=t_head_node->theadnode;
    while (run->left!=NULL){
        run=run->left;
    }
    return run;
}

void mirror(struct node* m_node){
    while (m_node!=NULL){
        mirror(m_node=m_node->left);
        mirror(m_node=m_node->right);
        struct node* temp=m_node->left;
        m_node->left=m_node->right;
        m_node->right=temp;
    }
}

void preorder(struct node* t_head_node){
    if (t_head_node!=NULL){
        printf("%d<-> ",t_head_node->data);
        preorder(t_head_node->left);
        preorder(t_head_node->right);
    }
}

void inorder(struct node* t_head_node){
    if (t_head_node!=NULL){
        inorder(t_head_node->left);
        printf("%d<-> ",t_head_node->data);
        inorder(t_head_node->right);
    }
}

void postorder(struct node* t_head_node){
    if (t_head_node!=NULL){
        postorder(t_head_node->left);
        postorder(t_head_node->right);
        printf("%d<-> ",t_head_node->data);
    }
}