#include <iostream>
#include <string>
using namespace std;


class node
{
private:
    int data;
    node* next;
public:
   node::node(int new_data){
   }
    ~node();
};

class list
{
private:
    /* data */
    node* l_head_node;
public:
    list(/* args */);
    ~list();
};

list::list(/* args */)
{
    l_head_node=new node(-1);
}

list::~list()
{
}


int main(){
    return 0;
}