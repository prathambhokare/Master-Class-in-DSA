#include <iostream>
#include <string>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class bst{
    public:
    node* t_head_node;
    int nr_nodes;
    bst(){
        t_head_node=NULL;
    }
    void insertintotree(int data);
    void inorder();
    void preorder();
    void postorder();
    void search(int data);
    void deletenode(int data);
};


void bst::insertintotree(int data){
    if (t_head_node==NULL){
        t_head_node=new node(data);
    }
    else{
        while (1){
        node* p_run=t_head_node;
        if (p_run->data>data){
            //moving to the left side
            if (p_run->left==NULL){
                p_run->left=new node(data);
                break;
            }
            else{
                p_run=p_run->left;
            }
        }
        else if (p_run->data==data){
            //invalid node bst not allow to store the duplicate items
            cout<<"bst is not allow to store the duplicate value in the tree"<<"\n";
        }
        else{
            //moving to the right side
            if (p_run->right==NULL){
                p_run->right=new node(data);
                break;
            }
            else{
                p_run=p_run->right;
            }
        }
        }
    }
}

int main(){
    node* p=new node(2);
    cout<<p->data<<"\n";
    return 0;
}