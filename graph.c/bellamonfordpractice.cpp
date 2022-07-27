#include <iostream>
#include <string>
using namespace std;


struct vertex{
    int v_id;
    int d;
    int pred;
};

struct edge{
    int src;
    int dest;
    int weight;
};



void display(struct edge e[],int n){
    for (int i=0;i<n;i++){
        cout<<e[i].src<<"   "<<e[i].dest<<"   "<<e[i].weight<<"\n";
    }
}

bool bellmon_ford(struct vertex v[],int n_v,struct edge e[],int n_e,int src){
    v[src].d=0;
    for (int i=0;i<n_v-1;i++){
        for (int j=0;j<n_e;j++){
            //relax(u,v,w)
            if (v[e[j].dest].d>(v[e[j].src].d+e[j].weight)){
                v[e[j].dest].d=v[e[j].src].d+e[j].weight;
                v[e[j].dest].pred=e[j].src;
                cout<<"true here"<<"\n";
            }
        }
    }
    for (int j=0;j<n_e;j++){
        if (v[e[j].dest].d>(v[e[j].src].d+e[j].weight)){
            return false;//negative edge cycle
        }
    }
    return true;
}

void shortestpath(struct vertex v[],int n_v,int dest){
    int i=dest;
    int totaldistance=v[i].d;
    cout<<"the total distance is"<<totaldistance<<"\n";
    while (true){
        cout<<i<<" ";
        i=v[i].pred;
        if (v[i].pred==-1){
            break;
        }
    }
    cout<<"\n";
}

int main(){
    int n_v;
    cout<<"Enter the number of vertex"<<"\n";
    cin>>n_v;
    struct vertex v[n_v];
    for (int i=0;i<n_v;i++){
        v[i].v_id=i;
        v[i].d=696969;
        v[i].pred=-1;
    }
    int n_e;
    cout<<"Enter the number of edges"<<"\n";
    cin>>n_e;
    struct edge e[n_e];
    for (int i=0;i<n_e;i++){
        int s;
        int d;
        int w;
        cout<<"Enter the source,destination and weight for edge"<<i<<"\n";
        cin>>s;
        cin>>d;
        cin>>w;
        e[i].src=s;
        e[i].dest=d;
        e[i].weight=w;
    }
    display(e,n_e);
    bellmon_ford(v,n_v,e,n_e,0);
    /*if (bellmon_ford(v,n_v,e,n_e)){
        cout<<"the negative cycle is not there"<<"\n";
    }
    else{
        cout<<"the negative cycle is there"<<"\n";
    }*/
    display(e,n_e);
    cout<<"vertexes are"<<"\n";
    for (int i=0;i<n_v;i++){
        cout<<v[i].v_id<<"   "<<v[i].d<<"   "<<v[i].pred<<"\n";
    }
    shortestpath(v,n_v,3);
    return 0;
}