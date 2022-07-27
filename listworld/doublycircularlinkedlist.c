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

int main(){
    struct node* p;
    p=createList();
    //printf("%d\n",p->data);
    insert_start(p,3);
    remove_end(p);
    insert_start(p,4);
    pop_end(p);
    insert_start(p,5);
    insert_start(p,6);
    insert_start(p,7);
    insert_end(p,8);
    printf("the previous value is %d\n",p->prev->data);
    printf("the length is %d\n",get_length(p));
    //remove_beg(p);
    //remove_end(p);
    //printf("%d\n",p->next->data);
    //printf("items at beganing of list is %d \n",get_beg(p));
    //printf("items at beganing of list is %d \n",get_end(p));
    //pop_beg(p);
    //pop_end(p);
    //remove_end(p);
    //conctenate(p,p);
    struct node* p1=createList();
    struct node* p2=createList();
    insert_end(p1,1);
    insert_end(p1,2);
    insert_end(p1,3);
    insert_end(p1,4);
    insert_end(p2,1);
    insert_end(p2,2);
    insert_end(p2,3);
    insert_end(p2,4);
    merge(p1,p2);
    //reverselist(p);
    //printf("the item is present %d\n",search(p,8));
    //p=appendlist(p1,p2);
    reverselis(p1);
    displaylist(p1);
    return 0;
}