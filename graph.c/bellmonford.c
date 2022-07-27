#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define white 0
#define gray 1
#define black 2

struct hnode{
    int v_id;
    struct hnode* next;
    struct hnode* next;
    double w;
};


struct vnode{
    int v_id;
    struct vnode* next;
    struct vnode* prev;
    struct hnode* hheadnode;
    double d;
    int color;
};


struct edge{
    struct vnode* src;
    struct vnode* dst;
    double weight;
};

struct graph{
    struct vnode* vlist_hp;
    struct edge* elist_hp;
    int nr_vertices;
    int nr_edges;
};


int main(){
    return 0;
}