#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int binarysearchrecursive(int* a,int s,int e,int search){
    if (s<=e){
        int mid=(s+e)/2;
        if (search>a[mid]){
            binarysearchrecursive(a,mid+1,e,search);
        }
        else if (search==a[mid]){
            return 1;
        }
        else{
            binarysearchrecursive(a,s,mid-1,search);
        }
    }
    return -1;
}
int main(){
    int a[]={1,2,3,4,5};
    printf("%d\n",binarysearchrecursive(a,0,5,7));
    return 0;
}