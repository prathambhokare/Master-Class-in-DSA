#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//pointer to the function

void bubble_sort(int* pa,int size){
    for (int i=0;i<size;i++){
        for (int j=0;j<(size-i)-1;j++){
            if (pa[j]>pa[j+1]){
                int a=pa[j];
                pa[j]=pa[j+1];
                pa[j+1]=a;
            }
        }
    }
}

void selection_sort(int* pa,int size){
    for (int i=0;i<size;i++){//o(n^2)
        int min=pa[i];
        int index=i;
        for (int j=i+1;j<size;j++){
            if (min>=pa[j]){
                min=pa[j];
                index=j;
            }
        }
        pa[index]=pa[i];
        pa[i]=min;
    }
}


void insertion_sort(int* pa,int size){
    for (int i=1;i<size;i++){
        int j=i-1;
        while (j>-1){
            if (pa[j]>pa[j+1]){
                int a=pa[j];
                pa[j]=pa[j+1];
                pa[j+1]=a;
            }
            j--;
        }
    }
}

void sortin_function(void (*pfn_A)(int*,int),int* a,int n){
    pfn_A(a,n);
}



int main(){
    void (*pfn_A[3])(int*,int)={bubble_sort,selection_sort,insertion_sort};
    int choice;
    printf("Emnter the your choice\n");
    scanf("%d\n",&choice);
    printf("1->bubble_sort,2->selection_sort,3->insertion_sort\n");
    if (choice<1 || choice>3){
        puts("bad choice");
        exit(-1);
    }
    int b[]={5,4,3,2,1};
    int n=5;
    sortin_function(pfn_A[choice-1],b,n);
    for (int i=0;i<5;i++){
        printf("%d\n",b[i]);
    }
    return 0;
}