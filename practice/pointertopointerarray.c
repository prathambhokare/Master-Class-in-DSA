#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){
    char** p;
    p=(char**)malloc(5*sizeof(char*));
    for (int i=0;i<5;i++){
        p[i]=(char*)malloc(3*sizeof(char));
        p[i]='ab';
    }
    printf("%s\n",p[0]);
    return 0;
}