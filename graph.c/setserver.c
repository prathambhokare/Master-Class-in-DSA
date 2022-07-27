#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "set.h"



struct node* create_set(void){
    return create_list();
}

struct node* set_union(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node* sethead2=p_set_2->next;
    struct node* union1=create_set();
    while (sethead1!=NULL){
        insert_end(union1,sethead1->data);
        sethead1=sethead1->next;
    }
    while (sethead2!=p_set_2){
        if (!is_member(p_set_1,sethead2->data)){
            insert_end(union1,sethead2->data);
        }
        sethead2=sethead2->next;
    }
    return union1;
}


struct node* set_intersection(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node* sethead2=p_set_2->next;
    struct node* intersection=create_set();
    while (sethead2!=NULL){
        if (is_member(p_set_1,sethead2->data)){
            insert_beg(intersection,sethead2->data);
        }
        sethead2=sethead2->next;
    }
    return intersection;
}


struct node* st_diff(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node* sethead2=p_set_2->next;
    struct node* setdifference=create_set();
    while (sethead1!=NULL){
        if (!is_member(p_set_2,sethead1->data)){
            insert_end(setdifference,sethead1->data);
        }
        sethead1=sethead1->next;
    }
    return setdifference;
}


struct node* set_symmetric_difference(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node* sethead2=p_set_2->next;
    struct node* symmetricdifference=create_set();
    struct node* diff1=st_diff(p_set_1,p_set,2);
    struct node* diff2=st_diff(p_set_2,p_set_1);
    symmetricdifference=set_union(diff1,diff2);
    return symmetricdifference;
}

int is_subset(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node*sethead2=p_set_2->next;
    int c=0;
    while (sethead1!=NULL){
        if (is_member(p_set_2,sethead1->data)){
            c=1;
        }
        sethead1=sethead1->next;
    }
    return c;
}


int is_superset(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node* sethead2=p_set_2->next;
    int c=0;
    while (sethead2!=NULL){
        if (is_member(p_set_1,sethead2->data)){
            c=1;
        }
        sethead2=sethead2->next;
    }
    return c;
}


int add_element(struct node* p_set, int element){
    if (!is_member(p_set,element)){
        insert_beg(p_set,element);
    }
}

int remove_element(struct node* p_set, int element){
    remove_element(p_set,element);
}

int is_member(struct node* p_set, int data){
    if (locate_node(p_set,data)==NULL){
        return 0;
    }
    else{
        return 1;
    }
}