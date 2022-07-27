#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createList(){
    struct node* p_list;
    p_list=(struct node*)malloc(sizeof(struct node));
    if (p_list==NULL){
        printf("error occured");
    }
    p_list->data=-1;
    p_list->next=p_list;
    p_list->prev=p_list;
    return p_list;
}


int insert_start(struct node* p_head_node, int new_data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("error occured");
    }
    temp->data=new_data;
    temp->next=p_head_node->next;
    temp->prev=p_head_node;
    p_head_node->next->prev=temp;
    p_head_node->next=temp;
}


int insert_end(struct node* p_head_node, int new_data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=new_data;
    if (temp==NULL){
        printf("error occured");
    }
    p_head_node->prev->next=temp;
    temp->prev=p_head_node->prev->next;
    temp->next=p_head_node;
    p_head_node->prev=temp;

}


int insert_after(struct node* p_head_node, int existing_data, int new_data){
    struct node* p_newnode;
    struct node* temp;
    struct node* exising_node;
    temp=temp->next;
    while (temp!=p_head_node){
        if (temp->data==existing_data){
            break;
        }
        temp=temp->next;
    }
    exising_node=temp;
    if (temp==p_head_node){
        return (1);
    }
    p_newnode=(struct node*)malloc(sizeof(struct node));
    if (p_newnode==NULL){
        printf("error is occured");
    }
    exising_node=temp;
    exising_node->next->prev=p_newnode;
    p_newnode->next=exising_node->next;
    exising_node->next=p_newnode;
    p_newnode->prev=exising_node;
}

int insert_before(struct node* p_head_node, int existing_data, int new_data){
    struct node* p_newnode;
    struct node* temp;
    struct node* exising_node;
    temp=temp->next;
    while (temp!=p_head_node){
        if (temp->data==existing_data){
            break;
        }
        temp=temp->next;
    }
    exising_node=temp;
    if (temp==p_head_node){
        return (1);
    }
    p_newnode=(struct node*)malloc(sizeof(struct node));
    if (p_newnode==NULL){
        printf("error is occured");
    }
    exising_node=temp;
    p_newnode->prev=exising_node->prev;
    p_newnode->next=exising_node;
    exising_node->prev=p_newnode;
    exising_node->prev->next=p_newnode;

}


int remove_beg(struct node* p_head_node){
    if (p_head_node->next==p_head_node && p_head_node->prev==p_head_node){
        printf("list is empty");
        return(0);
    }
    struct node* temp=p_head_node->next;
    p_head_node->next=p_head_node->next->next;
    free(temp);
    temp=NULL;
}


int remove_end(struct node* p_head_node){
    if (p_head_node->next==p_head_node && p_head_node->prev==p_head_node){
        printf("list is empty");
        return(0);
    }
    struct node* temp=p_head_node->prev;
    p_head_node->prev->prev->next=p_head_node;
    p_head_node->prev=p_head_node->prev->prev;
    free(temp);
    temp=NULL;
}


int remove_data(struct node* p_head_node,int r_data){
    struct node* p_newnode;
    struct node* temp;
    struct node* exising_node;
    temp=temp->next;
    while (temp!=p_head_node){
        if (temp->data==r_data){
            break;
        }
        temp=temp->next;
    }
    exising_node=temp;
    if (temp==p_head_node){
        return (1);
    }
    p_newnode=(struct node*)malloc(sizeof(struct node));
    if (p_newnode==NULL){
        printf("error is occured");
    }
    exising_node=temp;
    exising_node->prev->next=exising_node->next;
    exising_node->next->prev=exising_node->prev;
    free(exising_node);
    exising_node=NULL;
}




void displaylist(struct node* p_head_node){
    struct node* temp=p_head_node;
    temp=temp->next;
    printf("[START] <-> ");
    while (temp!=p_head_node){
        printf("[%d] <-> ",temp->data);
        temp=temp->next;
    }
    printf(" [END]\n");
}


void conctenate(struct node* p1,struct node* p2){
    struct node* p3=createList();
    struct node* temp1=p1->next;
    struct node* temp2=p2->next;
    while (temp1!=p1){
        insert_end(p3,temp1->data);
        temp1=temp1->next;
    }
    while (temp2!=p2){
        insert_end(p3,temp2->data);
        temp2=temp2->next;
    }
    displaylist(p3);
}

int isempty(struct node* p_head_node){
    if (p_head_node->next==p_head_node && p_head_node->prev==p_head_node){
        return 1;
    }
    return 0;
}


int get_beg(struct node* p_head_node){
    if (isempty(p_head_node)){
        printf("empty list\n");
        return 0;
    }
    return p_head_node->next->data;
}

int get_end(struct node* p_head_node){
    if (isempty(p_head_node)){
        printf("empty list\n");
        return 0;
    }
    return p_head_node->prev->data;
}

int pop_beg(struct node* p_head_node){
    if (isempty(p_head_node)){
        printf("empty list\n");
        return 0;
    }
    struct node* temp=p_head_node->next;
    p_head_node->next->next->prev=p_head_node;
    p_head_node->next=p_head_node->next->next;
    free(temp);
    temp=NULL;
    return 1;
}


int pop_end(struct node* p_head_node){
    if (isempty(p_head_node)){
        printf("empty list\n");
        return 0;
    }
    p_head_node->next->prev = p_head_node->prev; 
    p_head_node->prev->next = p_head_node->next; 
    free(p_head_node->prev);   
    return 1;
}


int get_length(struct node* p_head_node){
    struct node* temp=p_head_node;
    int len=0;
    for (temp=temp->next;temp!=p_head_node;temp=temp->next,++len);
    return len;
}


void merge(struct node* p1,struct node* p2){
    struct node* p3=createList();
    struct node* temp1=p1->next;
    struct node* temp2=p2->next;
    while (1){
        if (temp1==p1){
            while (temp2!=p2){
                insert_end(p3,temp2->data);
                temp2=temp2->next;
            }
            break;
        }
        if (temp2==p2){
            while (temp1!=p1){
                insert_end(p3,temp1->data);
                temp1=temp1->next;
            }
            break;
        }
        if (temp1->data<=temp2->data){
            insert_end(p3,temp1->data);
            temp1=temp1->next;
        }
        else{
            insert_end(p3,temp2->data);
            temp2=temp2->next;
        }
    }
    displaylist(p3);
}


void reverselist(struct node* p){
    struct node* p1=createList();
    struct node* temp=p->next;
    while (temp!=p){
        insert_start(p1,temp->data);
        temp=temp->next;
    }
    displaylist(p1); 
}

int search(struct node* p,int search_data){
    struct node* temp=p->next;
    while (temp!=p){
        if (temp->data==search_data){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


struct node* appendlist(struct node* p1,struct node* p2){
    if (isempty(p1) && isempty(p2)){
        return 0;
    }
    struct node* temp2=p2;
    p1->prev->next=temp2->next;
    temp2->next->prev=p1->prev;
    p1->prev=temp2->prev;
    temp2->prev->next=p1;
    return p1;
}


struct node* reverselis(struct node* p_head_node){
    struct node* temp1=p_head_node->next;
    struct node* temp2=p_head_node->prev;
    while (temp1->next!=temp2->prev){
        int temp=temp1->data;
        temp1->data=temp2->data;
        temp2->data=temp;
        temp1=temp1->next;
        temp2=temp2->prev;
    }
}

int is_member(struct node* p_set, int data){
    if (search(p_set,data)){
        return 1;
    }
    return 0;
}


struct node* create_set(void){
    return createList();
}

struct node* set_union(struct node* p_set_1, struct node* p_set_2){
    struct node* sethead1=p_set_1->next;
    struct node* sethead2=p_set_2->next;
    struct node* union1=create_set();
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
            insert_end(intersection,sethead2->data);
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
    struct node* diff1=st_diff(p_set_1,p_set_2);
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
        insert_end(p_set,element);
    }
}
int remove_element(struct node* p_set, int element){
    return remove_element(p_set,element);
}

void show(struct node* p_set){
    displaylist(p_set);
}

int main(){
    struct node* p=create_set();
    add_element(p,10);
    add_element(p,20);
    add_element(p,30);
    add_element(p,40);
    add_element(p,40);
    struct node* p1=create_set();
    add_element(p1,20);
    add_element(p1,40);
    add_element(p1,50);
    add_element(p1,60);
    show(p);
    show(p1);
    struct node* union1=set_union(p,p1);
    return 0;
}