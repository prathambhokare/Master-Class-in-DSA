#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){
    char a[25]="hghf";
    printf("%s\n",a);
    char* b;
    b=(char*)malloc(256*sizeof(char));
    b="hghf";
    printf("%s\n",b);
    char** p;
    p=(char**)malloc(5*sizeof(char*));
    p[0]=(char*)malloc(256*sizeof(char));
    *p[0]='hghf';
    printf("%s\n",*p[0]);
    return 0;

}