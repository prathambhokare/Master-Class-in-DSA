#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int partition(int a[],int){
}


void quicksort(int a[],int s,int e){
    if (s<e){
        int pivot=partition(a,s,e);
        quicksort(a,s,pivot-1);
        quicksort(a,pivot+1,e);
    }
}
int main(){
    return 0;
}