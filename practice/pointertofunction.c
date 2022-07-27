#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int (*myfunction(int,int))[5];
int main(){
    int (*pa)[5];
    int (*(*pfn)(int,int))[5];//crating the pointer to the function that acceting the two input as a integer returning the array of integer
    pfn=myfunction;
    pa=pfn(3,4);
    for (int i=0;i<5;i++){
        printf("%d\n",(*pa)[i]);
    }
    return 0;
}

int (*myfunction(int a,int b))[5]{
    static int A[5];
    A[0]=a+b;
    A[1]=a-b;
    A[2]=a*b;
    A[3]=a/b;
    A[4]=a*a;
    return &A;
}