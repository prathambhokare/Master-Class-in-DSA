#include <cstdlib>
#include <cstdio>
#include "list.h"
node::node(int new_data) : data(new_data), prev(0), next(0)
{

}

list::list() : p_head_node(new node(0))
{
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node;
}

list::~list()
{
    node* p_run; 
    node* p_run_next; 

    p_run = p_head_node->next; 
    while(p_run != p_head_node)
    {
        p_run_next = p_run->next; 
        delete p_run; 
        p_run = p_run_next; 
    }

    delete p_head_node; 
    p_head_node = 0; 
}

void list::generic_insert(node* beg,node* mid,node* end){
    mid->next=end;
    mid->prev=beg;
    beg->next=mid;
    beg->prev=mid;
}


void list::generic_delete(node* delete_node){
    delete_node->prev->next=delete_node->next;
    delete_node->next->prev=delete_node->prev;
}


node* list::search_node(int s_data){
    node* temp=p_head_node->next;
    while (temp!=p_head_node)
    {
        if (temp->data==s_data){
            return temp;
        }
        temp=temp->next;
    }

    return NULL;
}


status_t list::insert_start(int new_data){
    node* newnode=new node(new_data);
    generic_insert(p_head_node,newnode,p_head_node->next);
    return 1;
}

status_t list::insert_end(int new_data){
    node* newnode=new node(new_data);
    generic_insert(p_head_node->prev,newnode,p_head_node);
    return 1;
}


status_t list::insert_after(int e_data,int new_data){
    node* newnode=new node(new_data);
    node* s_node=search_node(e_data);
    generic_insert(s_node,newnode,s_node->next);
    return 1;
}


status_t list::insert_before(int e_data,int new_data){
    node* newnode=new node(new_data);
    node* s_node=search_node(e_data);
    generic_insert(s_node,newnode,s_node->prev);
    return 1;
}