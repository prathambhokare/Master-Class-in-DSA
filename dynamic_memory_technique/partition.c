#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void display(int a[],int s,int n){
    for (int i=s;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


/*int partition(int *a,int low ,int high){
			int pivot=a[high];
			int i=low-1;
			for (int j=low;j<=high-1;j++){
				if (a[j]<=pivot){
					i++;
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
	
	
			int temp=a[i+1];
			a[i+1]=a[high];
			a[high]=temp;
			return i+1;
}*/

int partition(int *a,int low,int high){
    int pivot=a[high];
    int i=low-1;
    for (int j=low;j<high;j++){
        if (a[j]<=pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}

		void quicksort(int *a,int l,int r){
			if (l<r){
				int p=partition(a,l,r);
				quicksort(a,l,p-1);
				quicksort(a,p+1,r);
			}
		}


/*int partition(int* a,int s,int e){
    int i=s-1;
    int pivot=a[e];
    for (int j=s;j<e;j++){
        if (a[i]<pivot){
            i=i+1;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[e];
    a[e]=temp;
    return i+1;
}

void quicksort(int* a,int s,int e){
    if  (s<e){
        int p=partition(a,s,e);
        quicksort(a,s,p-1);
        quicksort(a,p+1,e);
    }
}*/

int main(){
    int a[]={5,4,3,2,1};
    quicksort(a,0,4);
    display(a,0,5);
    return 0;
}