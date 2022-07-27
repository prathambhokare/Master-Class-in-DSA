#include <iostream>
#include <list>
#include <string>
using namespace std;

template <typename T>
class graph
{
private:
    T data;
    int nr_vetex;
    int nr_edges;
    list<T>* g_head_node;
    list<T>* h_list_head;
public:
    graph(T new_data) : data(new_data),nr_vetex(0),nr_edges(0){
        g_head_node=new list<T>;
        h_list_head=new list<T>;
    }
};
