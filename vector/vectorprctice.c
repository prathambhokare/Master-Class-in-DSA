#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vector{
    int* arr;
    int size;
};


struct vector* createvectorlist();
int push_back(struct vector* vec_point,int newdata);
void show(struct vector* vec_point);

int main(){
    struct vector* vec_point=createvectorlist();
    push_back(vec_point,10);
    push_back(vec_point,20);
    push_back(vec_point,30);
    push_back(vec_point,40);
    show(vec_point);
    return 0;
}

struct vector* createvectorlist(){
    struct vector* vec_point=(struct vector*)malloc(sizeof(struct vector));
    if (vec_point==NULL){
        printf("Error is occured\n");
    }
    memset(vec_point,0,sizeof(struct vector));
    vec_point->arr=NULL;
    vec_point->size=0;
    return vec_point;
}


int push_back(struct vector* vec_point,int newdata){
    vec_point->arr=(int*)realloc(vec_point->arr, (vec_point->size + 1)*sizeof(int));
    if (vec_point->arr=NULL){
        printf("Error is occured\n");
    }
    vec_point->size++;
    vec_point->arr[vec_point->size-1]=newdata;
}

void show(struct vector* vec_point){
    for (int i=0;i<vec_point->size;i++){
        printf("[ %d ]",vec_point->arr[i]);
    }
    printf("\n");
}