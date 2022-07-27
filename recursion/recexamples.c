#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void printele(int* a,int i,int n);
void printelereverse(int* a,int n);
int sum(int* a,int n);
int multiply(int* a,int first,int last);
void prime(int* a,int n);
int main(){
    int n;
    printf("Enter the sise of the array\n");
    scanf("%d",&n);
    int a[]={1,2,3,4,5};
    printele(a,0,n);
    printelereverse(a,n);
    printf("%d\n",sum(a,n-1));
    printf("%d\n",multiply(a,1,4));
    return 0;
}


void printele(int* a,int i,int n){
    if (i<n){
        printf("a[%d] is %d\n",i,a[i]);
        i=i+1;
        printele(a,i,n);
    }
}

void printelereverse(int* a,int n){
    if (n>0){
        n=n-1;
        printf("a[%d] is %d\n",n,a[n]);
        printelereverse(a,n);
    }
}

int sum(int* a,int n){
    if(n==-1){
        return 0;
    }
    else{
        return a[n]+sum(a,(n-1));
    }
}


int multiply(int* a,int first,int last){
    if (first>last){
        return 1;
    }
    else{
        return a[first]*multiply(a,first=first+1,last);
    }
}


void prime(int n){
    //prime numbers using the recursion
}