#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int merge(int a[],int low,int high,int mid);

int mergesort(int a[],int low,int high){
    if (low<=high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}


int merge(int a[],int low,int high,int mid){
}



int main(){
    int n=5;
    int a[]={5,4,3,2,1};
    mergesort(a,0,4);
    return (0);
}