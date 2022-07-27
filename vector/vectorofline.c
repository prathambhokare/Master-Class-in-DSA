#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vector_line{
    char** line;
    int size;
};

struct vector_line* createvector();
void push_back();



int main(){
    char** p="text";
    printf("the text is %s\n",**p);
    return 0;
}