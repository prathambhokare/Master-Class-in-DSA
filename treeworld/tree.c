#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* getnode(int newdata){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Error is occured\n");
    }
    memset(temp,0,sizeof(struct node));
    temp->data=newdata;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node* root,int data){
    struct node* temp=root;
    if (root==NULL){
        temp=getnode(data);
        printf("Creting root here\n");
    }
    else{
        if (root->data==data){
            printf("Duplicate data\n");
            return temp;
        }
        else if (root->data<data){
            if (root->right==NULL){
                printf("i am in right side\n");
                root->right=getnode(data);
            }
            else{
                root=root->right;
            }
        }
        else {
            if (root->left==NULL){
                printf("i am in left side\n");
                root->left=getnode(data);
            }
            else{
                root=root->left;
            }
        }
    }
    return temp;
}

void inorder(struct node* root){
    if (root!=NULL){
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
    }
}

void preorder(struct node* root){
    if (root!=NULL){
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);
    }
}

int main(){
    struct node* treeroot=NULL;
    treeroot=insert(treeroot,5);
    insert(treeroot,6);
    insert(treeroot,4);
    insert(treeroot,4);
    //printf("%d\n",treeroot->left->data);
    inorder(treeroot);
    preorder(treeroot);
    postorder(treeroot);
    return 0;
}