#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node* next;
}


struct node* createList(){
    struct node* p=NULL;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error occured\n");
    }
    p->data=-1;
    p->next=NULL;
    return p;
}


struct node* getnode(int x){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL){
        printf("Error occured");
    }
    p->data=x;
    p->next=NULL;
    return p;
}

void enqueue(struct node* p,int x){
    struct node* newnode;
    newnode=getnode(x);
    if (front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;   
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}


int dequeue(struct node* p){
    int val=0;
    if(front==NULL){
        return val;
    }
    else{
        struct node* temp;
        temp=front;
        val=temp->data;
        front=front->next;
        free(temp);
        temp=NULL;          
    }
    return val;
}

int present(int n){
    if (front==NULL){
        return 0;
    }
    else{
        while (front!=NULL){
            if (front->data==n){
                return 1;
            }
            front=front->next;
       }
    }
    return 0;
}


void display(){
    while (front!=NULL){
        printf("%d\n",front->data);
        front=front->next;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    return 0;
}