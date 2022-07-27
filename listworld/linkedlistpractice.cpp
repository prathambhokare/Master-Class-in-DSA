#include <iostream>
#include <string>
using namespace std;


struct node{
    int data;
    node* next;
};


node* createLinkedlist();
node* getNode(int data);


void insertatbeg(node* head,int data);
void insertatend(node* head,int data);


void deleteatbeg(node* head);
void deleteatend(node* head);


void display(node* head);



int main(){
    node* p=createLinkedlist();
    cout<<p->data<<"\n";
    insertatbeg(p,20);
    insertatbeg(p,30);
    insertatend(p,40);
    deleteatbeg(p);
    deleteatend(p);
    cout<<p->next->data<<"\n";
    display(p);
    return 0;
}


node* createLinkedlist(){
    return getNode(-1);
}



node* getNode(int data){
    node* newnode=NULL;
    newnode=new node();
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}



void insertatbeg(node* head,int data){
    node* newnode=getNode(data);
    newnode->next=NULL;
    newnode->next=head->next;
    head->next=newnode;
}



void insertatend(node* head,int data){
    node* temp=head;
    node* newnode=getNode(data);
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;   
}



void deleteatbeg(node* head){
    if (head->next==NULL){
        cout<<"Error is Occured"<<"\n";
    }
    else{
        node* temp=head->next;
        head->next=head->next->next;
        free(temp);
        temp=NULL;
    }
}

void deleteatend(node* head){
    if (head==NULL){
        cout<<"Error is Occured"<<"\n";
    }
    else{
        node* temp=head;
        node* prev=NULL;
        while (temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        cout<<"previous node is"<<prev->data<<"\n";
        free(temp);
        temp=NULL;
    }
}


void display(node* head){
    node* temp=head->next;
    while (temp!=NULL){
        cout<<" ["<<temp->data<<"] "<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}