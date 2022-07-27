#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n1;
    int n2;
    cout<<"Enter the n1 and n2"<<"\n";
    cin>>n1;
    cin>>n2;
    int i;
    int** p;
    p=(int**)malloc(n1*sizeof(int*));
    assert(p!=NULL);
    for (i=0;i<n1;i++){
        int satindex;
        cout<<"Enter the number of elements of an subarray"<<"\n";
        cin>>satindex;
        int j;
        int* sub;
        sub=(int*)malloc(satindex*sizeof(int));
        assert(sub!=NULL);
        p[i]=sub;
        for (j=0;j<satindex;j++){
            cin>>sub[j];
        }
        cout<<"subarray elements are"<<"\n";
        for (int i=0;i<satindex;i++){
            cout<<sub[i]<<"\n";
        }
        free(sub);
        sub=NULL;
    }
    cout<<"elements strored in *p"<<"\n";
    for  (int i=0;i<n1;i++){
        cout<<p[i]<<"\n";
    }
    int m;
    int n;
    for (int i=0;i<n2;i++){
        cin>>m;
        cin>>n;
        cout<<p[m]<<"\n";
    }  
    return 0;
}