#include <iostream>
#include <string>
using namespace std;


void print(int a[],int i,int n){//print all the elements of an array
    if (i<n){
        cout<<a[i]<<"\n";
        print(a,i=i+1,n);
    }
}

int sum(int a[],int n){//print the sum of array recursively
    if  (n==-1){
        return (0);
    }
    else{
        return a[n]+sum(a,n=n-1);
    }
}
int main(){
    int a[]={1,2,3,4,5,6};
    print(a,0,6);
    cout<<sum(a,5)<<"\n";
    return 0;
}