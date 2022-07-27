#include <stdio.h>
#include <stdlib.h>


int main(void){
    int a[5];
    //int* p=(int*)malloc(5*sizeof(int));
    int* p=(int*)&a;//nusta address deun fayda nahi karan ki kiti bytes vachayache is depend type of the array so we need typecasting nahitar to void* return karto
    for (int i=0;i<5;i++){
        p[i]=(i+1)*10;
    }
    for (int i=0;i<5;i++){
        printf("value of a[%d]=%d\n",i,p[i]);
    }
    return (0);
}