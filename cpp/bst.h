#pragma once

const int SUCCESS = 1;

typedef int data_t;
typedef int status_t;
typedef int len_t;
enum color;
typedef int data_t;
typedef int ret_t;
typedef int bool;

class bst_node
{
    friend class bst;
    friend class pbstnode;

private:
    data_t data;
    bst_node *left;
    bst_node *right;
    bst_node *parent;
    bst_node(data_t new_data);
};



class bst
{
private:
    bst_node *root_node;
    size_t nr_bytes;
    bst_node *search_bst_node(bst_node*p_root_node, data_t search_data);
    bst_node *get_bst_node(data_t new_data);
    bst_node *inorder_successor_node(bst_node *p_bst_node);
    bst_node *inorder_predecessor_node(bst_node *p_bst_node);
    void __inorder_r(bst_node *p_root_node);
    void __preorder_r(bst_node *p_root_node);
    void __postorder_r(bst_node *p_root_node);
    void __destroy_bst_r(bst_node *p_root_node);
    void transplant_bst(bst *p_bst, bst_node *u, bst_node *v);

public:
    bst();
    ~bst();
    bool search_bst(data_t search_data);
    void inorder_r();
    void preorder_r();
    void postorder_r();
    void inorder_nrc();
    void preorder_nrc();
    void postorder_nrc();
    ret_t maximum_bst(data_t *p_max_data);
    ret_t minimum_bst(data_t *p_min_data);
    ret_t inorder_successor(data_t e_data, data_t *p_succ_data);
    ret_t inorder_predecessor(data_t e_data, data_t *p_pred_data);
    ret_t remove_bst(data_t d_data);
    ret_t remove_bst_extended(data_t r_data);
};


enum color
{
    WHITE,
    GREY,
    BLACK
};

class pbstnode
{
private:
    bst_node *p_bst_node;
    pbstnode *prev;
    color_t color;
    pbstnode *next;

public:
    pbastnode(bst_node *newnode);
    ~pbastnode();
};

class pbstnode1
{
private:
    pbstnode *pbstnode_head;

public:
    pbstnode1();
    ~pbstnode1();
};
