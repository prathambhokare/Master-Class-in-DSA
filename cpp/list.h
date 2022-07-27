#pragma once 

const int SUCCESS = 1; 

typedef int data_t; 
typedef int status_t; 
typedef int len_t;


class node
{
    friend class list; 
    private: 
        data_t data; 
        node* prev; 
        node* next; 
        node(int new_data);//constructor to initialize the node 
}; 

class list
{
    private: 
        node* p_head_node; 

        static void generic_insert(node* p_beg, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(data_t s_data);

    public: 
        list();//constructor to initialize the list head node
        ~list(); 
        
        status_t insert_start(data_t new_data); 
        status_t insert_end(data_t new_data); 
        status_t insert_after(data_t e_data, data_t new_data); 
        status_t insert_before(data_t e_data, data_t new_data); 
        
        status_t get_start(data_t* p_start_data); 
        status_t get_end(data_t* p_end_data); 
        
        status_t pop_start(data_t* p_start_data); 
        status_t pop_end(data_t* p_end_data); 
        
        status_t remove_start(); 
        status_t remove_end(); 
        status_t remove_data(data_t r_data); 
        
        bool is_empty() const; 
        bool contains(data_t f_data) const; 
        len_t get_length(); 
        void show() const; 
        
        list* operator+(const list* other) const; 
        list* operator*(int n) const; 
        list* merge(const list* other) const;      
        list* get_reversed_list() const; 

        status_t append(const list* other); 
        status_t reverse(); 
}; 