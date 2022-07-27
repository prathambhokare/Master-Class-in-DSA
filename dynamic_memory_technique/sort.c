#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int* input(int size);
void output(int* a,int n);
void sort(int* b,int n);
void bubble_sort(int* c,int n);
void selection_sort(int* a,int n);
void insertion_sort(int* a,int n);
void quick_sort(int* a,int s,int e);
int partition(int* a,int s,int e);
void merge_sort(int* a,int s,int e);
void merge(int* a,int s,int mid,int e);


int main(int argc,int argv[]){
    printf("%d",argc);
    argc=5;
    int* p=NULL;
    p=(int*)malloc(argc*sizeof(int));
    assert(p!=NULL);
    memset(p,0,argc*sizeof(int));
    p=input(argc);
    output(p,argc);
    sort(p,argc);
    output(p,argc);
    return (0);
}

int* input(int a){
    int* p;
    p=(int*)malloc(a*sizeof(int));
    for (int i=0;i<a;i++){
        p[i]=(5-i);
    }
    return p;
}


void output(int* p,int n){
    for (int i=0;i<n;i++){
        printf("p[%d] is %d\n",i,p[i]);
    }
}


void sort(int* a,int n){
        //bubble_sort(a,n);
        //selection_sort(a,n);
        //insertion_sort(a,n);
        quick_sort(a,0,n-1);
        //merge_sort(a,0,n-1);
}

void bubble_sort(int* a,int n){
    for (int i=0;i<n;i++){//o(n^2)
        for  (int j=0;j<(n-i)-1;j++){
            if (a[j]>a[j+1]){
                int b=a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }
        }
    }
}

void selection_sort(int* a,int n){
    for (int i=0;i<n;i++){//o(n^2)
        int min=a[i];
        int index=i;
        for (int j=i+1;j<n;j++){
            if (min>=a[j]){
                min=a[j];
                index=j;
            }
        }
        a[index]=a[i];
        a[i]=min;
    }
}

void insertion_sort(int* a,int n){
    for (int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while (j>-1 && a[j]>a[j+1]){
            a[j]=a[j+1];
            j--;
        }
        a[j+1]=key;
    }
}

int partition(int* a,int s,int e){
    int i=s-1;
    int temp;
    int pivot=a[e+1];
    for (int j=s;j<e;j++){
        if (a[i]<=pivot){
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=pivot;
    pivot=a[i+1];
    a[i+1]=temp;
    return i+1;
}


void quick_sort(int* a,int s,int e){
    int pivot;
    if (s<e){
        pivot=partition(a,s,e);
        printf("pivot is %d\n",pivot);
        quick_sort(a,s,pivot-1);
        quick_sort(a,pivot+1,e);
    }
}


void merge(int*a,int low,int high,int m){
    int i=low;
    int j=m+1;
    int k=low;
    int temp[high];
    while (i<=m || j<high){
        if (a[i]<=a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
	}
    while (i<=m){
        temp[k]=a[i];
        k++;
        i++;
    }
    while (j<=high){
        temp[k]=a[j];
        k++;
        j++;
    }
    for (int p=low;p<=high;p++){
        a[p]=temp[p];
    }
}
void merge_sort(int*a,int low,int high){
    int mid;
    if (low<high){
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}