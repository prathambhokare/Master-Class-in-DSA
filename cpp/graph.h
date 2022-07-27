#include <iostream> 

const int SUCCESS = 1; 
typedef int vertex_t; 
typedef int status_t; 
typedef enum color color_t; 

enum color
{
    WHITE = 0, 
    GRAY, 
    BLACK 
}; 

class hnode
{
    friend class hlist; 
    friend class vnode; 
    friend class vlist; 
    friend class graph; 

    private: 
        vertex_t v; 
        double w; 
        hnode* prev; 
        hnode* next;     
}; 

class vnode
{
    friend class vlist; 
    friend class graph; 
    private: 
        vertex_t v; 
        color_t color; 
        hlist* ph_list; 
        vnode* pred_vertex; 
        double d_key; // d in case dijikstra, key in case of prim's  
}; 

class edge_node
{
    friend class edge_list; 
    friend class graph; 
    private: 
        vertex_t start_vertex; 
        vertex_t end_vertex; 
        double w; 

        edge_node* prev; 
        edge_node* next; 
}; 

class edge_list
{
    friend class graph; 
    private: 
        edge_node* p_edge_list; 
}; 

class hlist
{
    friend class graph; 
    private: 
        hnode* ph_list; 
}; 

class vlist
{
    friend class graph; 
    private: 
        vnode* pv_list; 
}; 


class vptr_to_vnode{
    friend class queue;
    friend class priorityqueue;
    friend class graph;
    friend class vptr_list;
    private:
        vnode* data;
        vptr_to_vnode* next;
        vptr_to_vnode* prev;
};


class vptr_list{
    friend class queue;
    friend class priorityqueue;
    friend class graph;
    private:
        vptr_to_vnode* head_node;
    public:
        vptr_list(vptr_to_vnode* newnode);
}

class queue{
    friend class graph;
    private:
    vptr_list* qheadnode;
    public:
        queue();
        ~queue();
}


class priorityqueue{
    friend class graph;
    private:
        vptr_list* pqheadnode;
    public:
    priorityqueue();
    ~priorityqueue();
}


class graph
{
    private: 
        vlist* pv_list; 
        edge_list* p_edge_list; 
        std::size_t nr_vertices; 
        std::size_t nr_edges; 
    public: 
        graph(); 
        ~graph(); 
        status_t add_vertex(vertex_t new_vertex); 
        status_t add_edge(vertex_t start_vertex, vertex_t end_vertex); 
        status_t add_edge_directed(vertex_t start_vertex, vertex_t end_vertex); 
        status_t remove_vertex(vertex_t r_vertex); 
        status_t remove_edge(vertex_t start_vertex, vertex_t end_vertex);              
        status_t remove_edge_directed(vertex_t start_vertex, vertex_t end_vertex);
        void show_graph(); 
        // friend std::ostream& operator<<(std::ostream&, const graph& g); 

        void reset_for_dfs();
        void reset_for_bfs(); 
        void reset_for_dijisktra(); 
        void reset_for_bellman_ford(); 
        void reset_prims(); 
        void reset_kruskal();  
        
        void dfs(); 
        void bfs(vertex_t source_vertex); 
        
        status_t dijikstra(vertex_t source_vertex); 
        status_t bellman_ford(); 
        status_t prims(vertex_t root_vertex); 
        status_t kruskal(); 
        
        void print_shortest_path_to(vertex_t destination_vertex, vertex_t source_vertex); 
        void print_all_shortest_paths(vertex_t source_vertex); 
        void print_mst(); 
}; 


// vnode* -> queue -> BFS  
// vnode* -> priority_queue -> DIJISTRA(d_key)PRIMS 
// relax() ? dfs_visit() ? 

// DCDS -> 