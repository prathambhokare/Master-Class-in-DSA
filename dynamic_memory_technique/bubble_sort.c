#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int* input(int n);
void ouput(int* p,int n);
void sort(int* p,int n);
void bubblesort(int* p,int n);
int main(int argc,int* argv[]){
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",n);
    int* p;
    p=(int*)malloc(n*sizeof(int));
    assert(p!=NULL);
    memset(p,0,n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",p[i]);
    }
    //p=input(n);
    //sort(p,n);
    //ouput(p,n);
    return 0;
}


int* input(int n){
    int* p=(int*)malloc(n*sizeof(int));
    assert(p!=NULL);
    memset(p,0,n*sizeof(int));
    int i;
    for (i=0;i<n;i++){
        scanf("Enter the elements at index %d and value %d",i,p[i]);
    }
    return p;
}


void ouput(int* p,int n){
    for (int i=0;i<n;i++){
        printf("value of a[%d] is %d",i,p[i]);
    }
}