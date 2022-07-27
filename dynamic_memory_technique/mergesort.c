#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int merge(int* a,int low,int high,int mid){
    int temp[high];
    int i=low;
    int j=mid+1;
    int k=low;
    while (i<=mid && j<high){
        if (a[i]>=a[j]){
            temp[k++]=a[j++];
        }
        else{
            temp[k++]=a[i++];
        }
    }
    while (i<=mid){
        temp[k++]=a[i++];
    }
    while (j<high){
        temp[k++]=a[j++];
    }
    for (int i=low;i<=high;i++){
        a[i]=temp[i];
    }
}

void mergesort(int a[],int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}
int main(){
    int n;
    printf("Enter the size\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of an array\n");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}