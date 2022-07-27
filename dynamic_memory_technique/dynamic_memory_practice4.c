#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct point
{
    double x,y,z;
};


void builtin_datatype(void);
void array_of_builtin_datatype(void);
void pointer_array_of_builtin_datatype(void);
void userdefined_datatype(void);
void array_of_userdefined_datatype(void);
void pointer_array_of_userdefided_datatype(void);


int main(void){
    builtin_datatype();
    array_of_builtin_datatype();
    pointer_array_of_builtin_datatype();
    userdefined_datatype();
    array_of_userdefined_datatype();
    pointer_array_of_userdefided_datatype();
    return (0);
}

void builtin_datatype(void)
{
    int* p;
    p=NULL;
    p=(int*)malloc(sizeof(int));
    assert(p!=NULL);
    *p=500;
    printf("*p=%d\n",*p);
    free(p);
    p=NULL;
}

void array_of_builtin_datatype(void){
    int* p;
    p=NULL;
    int a_size=5;
    int i;
    p=(int*)malloc(a_size*sizeof(int));
    assert(p!=NULL);
    memset(p,0,sizeof(int));
    for (i=0;i<a_size;i++){
        p[i]=(i+1)*10;
    }
    for(i=0;i<a_size;i++){
        printf("p[%d] is %d\n",i,p[i]);
    }
    free(p);
    p=NULL;
}

void pointer_array_of_builtin_datatype(void){
    int** p;
    p=NULL;
    int a_size=5;
    int i;
    p=(int**)malloc(a_size*sizeof(int*));
    assert(p!=NULL);
    memset(p,0,sizeof(int*));
    for (i=0;i<a_size;i++){
        p[i]=(int*)malloc(sizeof(int));
        assert(p[i]!=NULL);
        *p[i]=(i+1)*10;
    }
    for(i=0;i<a_size;i++){
        printf("*p[%d] is %d\n",i,p[i]);
    }
    for (i=0;i<a_size;i++){
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
}

void userdefined_datatype(void){
    struct point* p;
    p=NULL;
    p=(struct point*)malloc(sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,sizeof(struct point));
    p->x=1;
    p->y=2;
    p->z=3;
    printf("p->x is %2.lf\np->y is %2.lf\np->z is %2.lf\n",p->x,p->y,p->z);
    free(p);
    p=NULL;
}

void array_of_userdefined_datatype(void){
    struct point* p;
    p=NULL;
    int a_size=5;
    int i;
    p=(struct point*)malloc(sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(struct point));
    for (i=0;i<a_size;i++){
        p[i].x=(i+1)*10;
        p[i].y=(i+1)*20;
        p[i].z=(i+1)*30;
    }
    for (i =0;i<a_size;i++){
        printf("p[%d].x=%.2lf\np[%d].y=%.2lf\np[%d].z=%.2lf\n",i,p[i].x,i,p[i].y,i,p[i].z);
    }
    free(p);
    p=NULL;
}

void pointer_array_of_userdefided_datatype(void){
    struct point** p;
    p=NULL;
    int a_size=5;
    int i;
    p=(struct point**)malloc(a_size*sizeof(struct point*));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(struct point*));
    for (i=0;i<a_size;i++){
        p[i]=(struct point*)malloc(sizeof(struct point));
        assert(p[i]!=NULL);
        p[i]->x=(i+1)*10;
        p[i]->y=(i+1)*20;
        p[i]->z=(i+1)*30;
    }
    for(i=0;i<a_size;i++){
        printf("p[%d]->x=%2.lf\np[%d]->x=%2.lf\np[%d]->x=%2.lf\n",i,p[i]->x,i,p[i]->y,i,p[i]->z);
    }
    for(i=0;i<a_size;i++){
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
}