#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


struct point{
    double x,y,z;
};

void builtindatatype(void);
void array_of_builtdatatype(void);
void pointer_to_array_of_builtin_datatype(void);
void userdefineddatatype(void);
void array_of_userdefineddatatype(void);
void pointer_to_array_of_userdefineddatatype(void);

int main(void){
    builtindatatype();
    array_of_builtdatatype();
    pointer_to_array_of_builtin_datatype();
    userdefineddatatype();
    array_of_userdefineddatatype();
    pointer_to_array_of_userdefineddatatype();
    return (0);
}


void builtindatatype(void){
    int *p;
    p=(int*)malloc(sizeof(int));
    assert(p!=NULL);
    memset(p,0,sizeof(int));
    *p=5;
    printf("value of *p is %d\n",*p);
    free(p);
    p=NULL;
}

void array_of_builtdatatype(void){
    int *p;
    int a_size=5;
    int i;
    p=(int*)malloc(a_size*sizeof(int));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(int));
    for (i=0;i<a_size;i++){
        p[i]=(i+1)*10;
    }
    for (i=0;i<a_size;i++){
        printf("the value of p[%d] is %d\n",i,p[i]);
    }
    free(p);
    p=NULL;
}


void pointer_to_array_of_builtin_datatype(void){
    int **p;
    int a_size=5;
    int i;
    p=(int**)malloc(a_size*sizeof(int*));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(int*));
    for (i=0;i<a_size;i++){
        p[i]=(int*)malloc(sizeof(int));
        assert(p[i]!=NULL);
        *p[i]=(i+1)*10;
    }
    for (i=0;i<a_size;i++){
        printf("value of *p[%d] is %d\n",i,*p[i]);
    }
    for (i=0;i<a_size;i++){
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
}


void userdefineddatatype(void){
    struct point* p;
    p=(struct point*)malloc(sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,sizeof(struct point));
    p->x=4;
    p->y=5;
    p->z=6;
    printf("value of p->x is %2lf\nvalue of p->y is %2lf\nvalue of p->z is %2lfz",p->x,p->y,p->z);
    free(p);
    p=NULL;
}


void array_of_userdefineddatatype(void){
    struct point* p;
    int a_size=5;
    int i;
    p=(struct point*)malloc(a_size*sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,sizeof(a_size*sizeof(struct point)));
    for (i=0;i<a_size;i++){
        p[i].x=(i+1)*10;
        p[i].y=(i+2)*10;
        p[i].z=(i+3)*10;
    }
    for (i=0;i<a_size;i++){
        printf("value of p[%d]->x is %2lf\nvalue of p[%d]->y is %2lf\nvalue of p[%d]->z is %2lf\n",i,p[i].x,i,p[i].y,i,p[i].z);
    }
    free(p);
    p=NULL;
}


void pointer_to_array_of_userdefineddatatype(void){
    struct point** p1;
    p1=NULL;
    int a_size=5;
    int i;
    p1=(struct point**)sizeof(a_size*sizeof(struct point*));
    assert(p1!=NULL);
    memset(p1,0,a_size*sizeof(struct point*));
    for (i=0;i<a_size;i++){
        p1[i]=(struct point*)malloc(sizeof(struct point));
        assert(p1[i]!=NULL);
        p1[i]->x=(i+1)*1;
        p1[i]->y=(i+1)*2;
        p1[i]->z=(i+1)*3;
    }
    for (i=0;i<a_size;i++){
        printf("value of p[%d]->x is %.2lf\nvalue of p[%d]->y is %.2lf\nvalue of p[%d]->z is %.2lf",i,p1[i]->x,i,p1[i]->y,i,p1[i]->z);
    }
    for (i=0;i<a_size;i++){
        free(p1[i]);
        p1[i]=NULL;
    }
    free(p1);
    p1=NULL;
}

/*
struct point** p;
    p=NULL;
    int a_size;
    int i;
    p=(struct point**)malloc(a_size*sizeof(struct point*));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(struct point*));
    for (i=0;i<a_size;i++){
        p[i]=(struct point*)malloc(sizeof(struct point));
        assert(p[i]!=NULL);
        p[i]->x=(i+1)*1;
        p[i]->y=(i+1)*2;
        p[i]->z=(i+1)*3;
    }
    for (i=0;i<a_size;i++){
        printf("*p[%d]->x=%.2lf\n*p[%d]->y=%.2lf\n*p[%d]->z=%.2lf\n",i,p[i]->x,i,p[i]->y,i,p[i]->z);
    }
    for (i=0;i<a_size;i++){
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
    */