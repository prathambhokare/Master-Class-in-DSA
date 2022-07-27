#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int data_t
typedef struct node node_t
typedef int status_t
typedef int len_t


struct node{
    data_t data;
    node_t* next;
};


node_t* createlist();



status_t insertbeg(node_t* p_head_node,data_t data);
status_t insertend(node_t* p_head_node,data_t data);0
status_t insertafter(node_t* p_head_node,data_t e_data,data_t data);
status_t insertbefore(node_t* p_head_node,data_t e_data,data_t data);


status_t removebeg(node_t* p_head_node,data_t** value);
status_t removened(node_t* p_head_node,data_t** value);
status_t removenode(node_t* p_head_node,data_t data,data_t** value);

node_t* getnode(data_t data);



int main(){
    return 0;
}