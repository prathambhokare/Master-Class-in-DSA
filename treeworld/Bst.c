#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int status;
struct bst_node{
    int data;
    struct bst_node* parent;
    struct bst_node* left;
    struct bst_node* right;
};

struct bst{
    struct bst_node* p_root_node;
    int nr_node;
};


void* xmalloc(size_t nr_bytes);
struct bst_node* getnode(int newdata);
status insert_bst(struct bst* p,int newdata);
struct bst* createbst();
void inorder(struct bst_node* p);
void preorder(struct bst_node* p);
void postorder(struct bst_node* p);
struct bst_node* seach_node(struct bst* p,int newdata);
struct bst_node* predecessor(struct bst* p,int newdata);
struct bst_node* successor(struct bst* p,int newdata);
int remove_node(struct bst* p,int newdata);
void mirror(struct bst* p);


int main(){
    struct bst* p=createbst();
    int a[]={100,50,150,25,75,125,175,65,130};
    for (int i=0;i<9;i++){
          insert_bst(p,a[i]);
    }
    struct bst_node* temp=seach_node(p,100);
    /*int ndata;
    printf("Enter the node of which the predecssor and successor to be find\n");
    scanf("%d ",&ndata);*/
    struct bst_node* temp1= successor(p,175);
    printf("the inorder successor is %d\n",temp1->data);
    struct bst_node* temp2=predecessor(p,175);
    printf("the predecessor data is %d\n",temp2->data);
    printf("search data is %d\n",temp->data);
    printf("inorder is :\n");
    inorder(p->p_root_node);
    printf("\npreorder is :\n");
    preorder(p->p_root_node);
    printf("\npostorder is:\n");
    postorder(p->p_root_node);
    printf("\n");
    remove_node(p,150);
    printf("inorder is\n");
    inorder(p->p_root_node);
    printf("\n");
    return 0;
}
/*inorder is :
[25] [50] [65] [75] [100] [125] [130] [150] [175]
preorder is :
[100] [50] [25] [75] [65] [150] [125] [130] [175]
postorder is:
[25] [65] [75] [50] [130] [125] [175] [150] [100]
*/



void inorder(struct bst_node* p){
    if (p!=NULL){
        inorder(p->left);
        printf("[%d] ",p->data);
        inorder(p->right);
    }
}

void preorder(struct bst_node* p){
    if (p!=NULL){
        printf("[%d] ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct bst_node* p){
    if (p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("[%d] ",p->data);
    }
}

struct bst* createbst(){
    return (struct bst*)xmalloc(sizeof(struct bst));
}

status insert_bst(struct bst* p,int newdata){
    struct bst_node* newnode=NULL;
    newnode=getnode(newdata);
    if (p->p_root_node==NULL){
        p->p_root_node=newnode;
        p->nr_node++;
        return 1;
    }
    else{
        struct bst_node* p_run;
        p_run=p->p_root_node;
        while (1){
        if (newdata<=p_run->data){
            if (p_run->left==NULL){
                p_run->left=newnode;
                newnode->parent=p_run;
                return 1;
            }
            else{
                p_run=p_run->left;
            }
        }
        else{
            if (p_run->right==NULL){
                p_run->right=newnode;
                newnode->parent=p_run;
                return 1;
            }
            else{
                p_run=p_run->right;
            }
        }
        }
    }
}



struct bst_node* seach_node(struct bst* p,int newdata){
    struct bst_node* newnode=p->p_root_node;
    if (newnode==NULL){
        return NULL;
    }
    while (newnode!=NULL){
    if (newdata>newnode->data){
        newnode=newnode->right;
    }
    else if (newnode->data==newdata){
        return newnode;
    }
    else{
        newnode=newnode->left;
    }
    }
    return NULL;
}



struct bst_node* successor(struct bst* p,int newdata){
    struct bst_node* x=seach_node(p,newdata);
    if (x->right!=NULL){
        x=x->right;
        while (x->left!=NULL){
            x=x->left;
        }
        return x;
    }
    else{
        struct bst_node* y=x->parent;
        while (y!=NULL && x==y->parent){
            x=y;
            y=x->parent;
        }
        return y;
    }
} 



struct bst_node* predecessor(struct bst* p,int newdata){
    struct bst_node* x=seach_node(p,newdata);
    if (x->left!=NULL){
        x=x->left;
        while (x->right!=NULL){
            x=x->right;
        }
    }
    else{
        struct bst_node* y=x->parent;
        while (y!=NULL && x==y->parent){
            x=y;
            y=x->parent;
        }
        x=y;
    }
    return x;
} 


struct bst_node* getnode(int newdata){
    struct bst_node* p_new_node=NULL;
    p_new_node=(struct bst_node*)xmalloc(sizeof(struct bst_node));
    p_new_node->data=newdata;
    p_new_node->left=NULL;
    p_new_node->right=NULL;
    p_new_node->parent=NULL;
    return p_new_node;
}



int remove_node(struct bst* p,int newdata){
    struct bst_node* r_node=seach_node(p,newdata);
    printf("node is %d\n",r_node->data);
    if (r_node==NULL){
        return 0;
    }
    if (r_node->left==NULL){
        if (r_node->parent->left==r_node){
            r_node->parent->left=r_node->right;
        }
        else{
              r_node->parent->right=r_node->left; 
        }
        free(r_node);
        r_node=NULL;
    }
    else if (r_node->right==NULL){
        if (r_node->parent->left==r_node){
            r_node->parent->left=r_node->right;
        }
        else{
            r_node->parent->right=r_node->left; 
        }
        free(r_node);
        r_node=NULL;
    }
    else{
        struct bst_node* succ=successor(p,r_node->data);
        int tempdata=succ->data;
        printf("data is %d\n",tempdata);
        if (succ->left==NULL){
        if (succ->parent->left==succ){
            succ->parent->left=succ->right;
        }
        else{
            succ->parent->right=succ->left; 
        }
        free(succ);
        succ=NULL;
    }
    else if (succ->right==NULL){
        if (succ->parent->left==succ){
            succ->parent->left=succ->right;
        }
        else{
            succ->parent->right=succ->left; 
        }
        free(succ);
        succ=NULL;
    }
    else{
    }
        r_node->data=tempdata;
        printf("updated data is %d\n",r_node->data);
    }
    return 1;
}

void* xmalloc(size_t nr_bytes){
    void* p=NULL;
    p=malloc(nr_bytes);
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,nr_bytes);
    return p;
}