#include <stdio.h> 
#include <stdlib.h> 

#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define G_INVALID_VERTEX 2 
#define G_INVALID_EDGE 3 
#define G_EDGE_EXISTS 4 
#define G_VERTEX_EXISTS 5 
#define G_NEGATIVE_PATH_CYCLE 6 

#define LIST_EMPTY  7 

typedef int vertex_t; 
typedef int status_t; 

typedef struct hnode hnode_t;
typedef hnode_t hlist_t;  

typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 

typedef struct edge_node edge_node_t;
typedef edge_node_t edge_list_t; 

typedef struct vnodeptr_node vnodeptr_node_t; 
typedef vnodeptr_node_t vnodeptr_list_t; 
typedef vnodeptr_stack_t vnodeptr_stack_t; 

typedef struct graph graph_t; 
 
enum color
{
    WHITE = 0, 
    GREY, 
    BLACK; 
}; 

struct hnode
{
    int v; 
    double w; 

    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode
{
    int v; 
    struct hnode* ph_head; 
    enum color c; 
    double d; 
    struct vnode* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct edge_node
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    double w; 

    struct edge_node* prev; 
    struct edge_node* next; 
}; 

struct vnodeptr_node
{
    struct vnode* pv; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

struct graph
{
    vlist_t* pv_list; 
    edge_list_t* p_edge_list; 
    int nr_vertices; 
    int nr_edges; 
}; 

/* graph management */ 
graph_t* create_graph(); 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t remove_vertex(graph_t* g, vertex_t v); 
/* directed edge from v_start to v_end */ 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void print_graph(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

status_t bellman_ford(graph_t* g, vertex_t s);
void reset(graph_t* g);  
void print_shortest_path(graph_t*, vertex_t s, vertex_t v); 
void print_all_shortest_paths(graph_t*, vertex_t s); 

/* hlist management */ 
hlist_t* h_create_list(); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v, double w); 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_get_node(vertex_t v); 

/* vlist management */ 
vlist_t* v_create_list(); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v); 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_get_node(vertex_t v); 

/* edge management */ 
edge_list_t* e_create_list(); 
status_t e_insert_end(edge_list_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, 
                        double w); 

edge_node_t* e_search_node(elist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end); 
void e_generic_insert(edge_node_t* pe_beg, edge_node_t* pe_mid, edge_node_t* pe_end); 
void e_generic_delete(edge_node_t* pe_delete_node); 
edge_node_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w); 

/* vnodeptr_stack management */ 
vnodeptr_stack_t* create_vnodeptr_stack(); 
status_t push_vnodeptr(vnodeptr_stack_t*, vnode_t*); 
status_t pop_vnodeptr(vnodeptr_stack_t*, vnode_t**); 
int is_vnodeptr_stack_empty(vnodeptr_stack_t*); 
status_t destroy_vnodeptr_stack(vnodeptr_stack_t**); 

/* vnodeptr_list_t management */ 
vnodeptr_list_t* vnodeptr_create_list(); 
status_t vnodeptr_insert_end(vnodeptr_list_t*, vnode_t*); 
status_t vnodeptr_pop_end(vnodeptr_list_t*, vnode_t**); 
status_t vnodeptr_destroy_list(vnodeptr_list_t* pp_list); 
void vnodeptr_generic_insert(vnodeptr_list_t*, vnodeptr_list_t*, vnodeptr_list_t*); 
void vnodeptr_generic_delete(vnodeptr_list_t*); 
vnodeptr_node_t* get_vnodeptr_node(vnode_t* p_new_node); 

void* xcalloc(size_t, size_t); 

int main(void)
{

}

graph_t* create_graph()
{
    graph_t* g = NULL; 

    g = (graph_t*)xcalloc(1, sizeof(graph_t)); 
    g->pv_list = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    
    /* initialize dummy node g->pv_list */ 
    g->pv_list->v = -1; 
    g->pv_list->ph_head = NULL; 
    g->pv_list->c = WHITE; 
    g->pv_list->d = 0.0; 
    g->pv_list->pred_vertex = NULL; 
    g->pv_list->prev = g->pv_list; 
    g->pv_list->next = g->pv_list; 

    /* allocate & initialize dummy node g->p_edge_list */ 
    g->p_edge_list = (edge_node_t*)e_get_node(NULL, NULL, 0.0); 
    g->p_edge_list->prev = g->p_edge_list; 
    g->p_edge_list->next = g->p_edge_list; 

    return (g); 
}

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w)
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    status_t s; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL)
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_end == NULL)
        return (G_INVALID_VERTEX); 

    s = h_insert_end(pv_start->ph_head, pv_end->v, w); 
    assert(s); 

    s = e_insert_end(g->p_edge_list, pv_start, pv_end, w); 
    assert(s); 

    return (SUCCESS); 
}

/* 
    for i = 1 to i = |G.V|-1 
        for every edge (u,v) (- G.E 
            RELAX(u, v, w)
*/ 
status_t bellman_ford(graph_t* g, vertex_t s)
{
    edge_node_t* p_edge_run = NULL; 
    int i; 
    const int N = g->nr_vertices; 

    for(i = 0; i < N-1; ++i)
    {
        for(p_edge_run = g->p_edge_list->next; 
            p_edge_run != g->p_edge_list; 
            p_edge_run = p_edge_run->next)
            
            relax(p_edge_run->pv_start, 
                p_edge_run->pv_end, 
                p_edge_run->w); 
        
    }

    for(p_edge_run = g->p_edge_list->next; 
        p_edge_run != g->p_edge_list; 
        p_edge_run = p_edge_run->next)
        if(p_edge_run->pv_end->d > p_edge_run->pv_start->d + p_edge_run->w)
            return (G_NEGATIVE_PATH_CYCLE); 
        
    return (SUCCESS); 
}

/* hlist management */ 
hlist_t* h_create_list()
{

}

status_t h_insert_end(hlist_t* ph_list, vertex_t v, double w)
{

}

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v)
{

}

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end)
{

}

void h_generic_delete(hnode_t* ph_delete_node)
{

}

hnode_t* h_get_node(vertex_t v)
{

}

/* vlist management */ 
vlist_t* v_create_list()
{

}

status_t v_insert_end(vlist_t* pv_list, vertex_t v)
{

}

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v)
{

}

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end)
{

}

void v_generic_delete(vnode_t* pv_delete_node)
{

}

vnode_t* v_get_node(vertex_t v)
{
    vnode_t* pv_node = NULL; 
    pv_node = (vnode_t*)xcalloc(1, 
    
    )
}

/* edge management */ 
edge_list_t* e_create_list()
{
    edge_node_t* pe_head = e_get_node(NULL, NULL, 0.0); 
    pe_head->prev = pe_head; 
    pe_head->next = pe_head; 
    return (pe_head); 
}

status_t e_insert_end(edge_list_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, 
                        double w)
{
    e_generic_insert(p_edge_list->prev, e_get_node(pv_start, pv_end, w), p_edge_list); 
    return (SUCCESS); 
}

edge_node_t* e_search_node(elist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end)
{
    edge_node_t* pe_node = NULL; 
    for(pe_node = p_edge_list->next; pe_node != p_edge_list; pe_node = pe_node->next) 
        if(pe_node->pv_start == pv_start && pe_node->pv_end == pv_end) 
            return pe_node; 
    return (NULL); 
}

void e_generic_insert(edge_node_t* pe_beg, edge_node_t* pe_mid, edge_node_t* pe_end)
{
    pe_mid->next = pe_end; 
    pe_mid->prev = pe_beg; 
    pe_beg->next = pe_mid; 
    pe_end->prev = pe_mid; 
}

void e_generic_delete(edge_node_t* pe_delete_node)
{
    pe_delete_node->prev->next = pe_delete_node->next; 
    pe_delete_node->next->prev = pe_delete_node->prev; 
    free(pe_delete_node); 
}

edge_node_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w)
{
    edge_node_t* p_edge_node = NULL; 
    p_edge_node = (edge_node_t*)xcalloc(1, sizeof(edge_node_t)); 
    p_edge_node->pv_start = pv_start; 
    p_edge_node->pv_end = pv_end; 
    p_edge_node->w = w; 

    return (p_edge_node); 
}

/* vnodeptr_stack management */ 
vnodeptr_stack_t* create_vnodeptr_stack(void)
{
    return create_vnodeptr_list(); 
}

status_t push_vnodeptr(vnodeptr_stack_t* p_stack, vnode_t* pv)
{
    return vnodeptr_insert_end(p_stack, pv); 
}

status_t pop_vnodeptr(vnodeptr_stack_t* p_stack, vnode_t** pp_v)
{
    return vnodeptr_pop_end(p_stack, pp_v); 
}

int is_vnodeptr_stack_empty(vnodeptr_stack_t* p_stack)
{
    return (p_stack->next == p_stack && p_stack->prev == p_stack); 
}

status_t destroy_vnodeptr_stack(vnodeptr_stack_t**)
{
    vnodeptr_stack_t* p_stack = *pp_stack; 
    vnodeptr_destroy_list(p_stack); 
    *pp_stack = NULL; 
    return (SUCCESS);  
}

/* vnodeptr_list_t management */ 
vnodeptr_list_t* vnodeptr_create_list()
{
    vnodeptr_list_t* p_vnodeptr_list = NULL; 
    p_vnodeptr_list = get_vnodeptr_node(NULL); 
    p_vnodeptr_list->prev = p_vnodeptr_list; 
    p_vnodeptr_list->next = p_vnodeptr_list; 

    return (p_vnodeptr_list); 
}

status_t vnodeptr_insert_end(vnodeptr_list_t* p_vnodeptr_list, vnode_t* pv)
{
    vnodeptr_generic_insert(p_vnodeptr_list->prev, get_vnodeptr_node(pv), p_vnodeptr_list); 
    return (SUCCESS); 
}

status_t vnodeptr_pop_end(vnodeptr_list_t* p_vnodeptr_list, vnode_t** pp_v)
{
    if(p_vnodeptr_list->prev == p_vnodeptr_list && p_vnodeptr_list->next == p_vnodeptr_list)
        return (LIST_EMPTY); 
    *pp_v = p_vnodeptr_list->prev->pv; 
    vnodeptr_generic_delete(p_vnodeptr_list->prev); 
    return (SUCCESS); 
}

status_t vnodeptr_destroy_list(vnodeptr_list_t** pp_list)
{
    vnodeptr_list_t* p_list = *pp_list; 
    vnodeptr_node_t* p_run = NULL; 
    vnodeptr_node_t* p_run_next = NULL; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next; 
        free(p_run); 
    }

    *pp_list = NULL; 
    return (SUCCESS); 
}

void vnodeptr_generic_insert(vnodeptr_list_t* p_beg, vnodeptr_list_t* p_mid, vnodeptr_list_t* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void vnodeptr_generic_delete(vnodeptr_list_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
}

vnodeptr_node_t* get_vnodeptr_node(vnode_t* p_new_node)
{
    vnodeptr_node_t* p_new_vnodeptr_node = NULL; 

    p_new_vnodeptr_node = (vnodeptr_node_t*)xcalloc(1, sizeof(vnodeptr_node_t)); 
    p_new_vnodeptr_node->pv = p_new_node; 
    p_new_vnodeptr_node->prev->next = p_new_vnodeptr_node->next; 
    p_new_vnodeptr_node->next->prev = p_new_vnodeptr_node->prev; 

    return (p_new_vnodeptr_node); 
}

void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL; 
    p = calloc(nr_elements, size_per_element); 
    assert(p); 
    return (p); 
}