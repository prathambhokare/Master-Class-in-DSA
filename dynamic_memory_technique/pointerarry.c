#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int main(){
    printf("hello world\n");
    int *p[5];
    for (int i=0;i<5;i++){
        *p[i]=(i+1)*10;
    }
    for (int i=0;i<5;i++){
        printf("%d",*p[i]);
    }
    return (0);
}