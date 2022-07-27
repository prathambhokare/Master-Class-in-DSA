#include <iostream>
#include <string>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;
        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

class BST{
    node* bstheadnode;
    public:
        BST(){
            bstheadnode=NULL;
        }
        void insertintobst(int data);
        void preorder();
        void inorder();
        void postorder();
        node* search(int data);
        void preorder_helper(node* headnode);
        void inorder_helper(node* headnode);
        void postorder_helper(node* headnode);
};



void BST::insertintobst(int data){
    node* newnode=new node(data);
    if (bstheadnode==NULL){
        bstheadnode=newnode;
    }
    else{
        node* temp=bstheadnode;
        while (1){
            if (temp->data>data){
                if (temp->left==NULL){
                    temp->left=newnode;
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if (temp->right==NULL){
                    temp->right==newnode;
                }
                else{
                    temp=temp->right;
                    break;
                }
            }
        }
    }
}


void BST::preorder(){
    if (bstheadnode!=NULL){
        preorder_helper(bstheadnode);
    }
}



void BST::inorder(){
    if (bstheadnode!=NULL){
        inorder_helper(bstheadnode);
    }
}



void BST::postorder(){
    if (bstheadnode!=NULL){
        postorder_helper(bstheadnode);
    }
}





void BST::preorder_helper(node* bstheadnode){
    if (bstheadnode!=NULL){
        cout<<" ["<<bstheadnode->data<<"] "<<"\n";
        preorder_helper(bstheadnode->left);
        preorder_helper(bstheadnode->right);
    }
}



void BST::inorder_helper(node* bstheadnode){
    if (bstheadnode!=NULL){
        inorder_helper(bstheadnode->left);
        cout<<" ["<<bstheadnode->data<<"] "<<"\n";
        inorder_helper(bstheadnode->right);
    }
}



void BST::postorder_helper(node* bstheadnode){
    if (bstheadnode!=NULL){
        postorder_helper(bstheadnode->left);
        postorder_helper(bstheadnode->right);
        cout<<" ["<<bstheadnode->data<<"] "<<"\n";
    }
}



int main(){
    BST p;
    p.insertintobst(2);
    p.insertintobst(5);
    p.insertintobst(1);
    return 0;
}