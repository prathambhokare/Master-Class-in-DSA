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
void pointer_array_of_userdefined_datatype(void);

int main(void)

{
    builtin_datatype();
    array_of_builtin_datatype();
    pointer_array_of_builtin_datatype();
    userdefined_datatype();
    array_of_userdefined_datatype();
    pointer_array_of_userdefined_datatype();
    return (0);
}

void builtin_datatype(void)
{
    int* p;//craeting an simple pointer(which is 8 byte compulsary nothing but the size of the address bus)
    p=NULL;//assign to the null
    puts("pointer to builtin datatype");
    p=(int*)malloc(sizeof(int));//assign memory address to it
    assert(p!=NULL);//check whether p gets an memory or not
    memset(p,0,sizeof(int));//seeting all the values of allocated memory to the zero
    *p=500;//deferencing means accesssing addresss for read and write
    printf("*p=%d\n",*p);//printing it
    free(p);//deallocate the memory (but still present in memory of os)
    p=NULL;//so for that purpose make it as null
}

void array_of_builtin_datatype(void)
{
    int* p;
    p=NULL;
    puts("pointer to the array");
    int a_size=5;
    p=(int*)malloc(a_size*sizeof(int));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(int));
    for (int i=0;i<a_size;i++){
        p[i]=(i+1)*100;
    }
    for (int i=0;i<a_size;i++){
        printf("p[%d]=%d\n",i,p[i]);
    }
    free(p);
    p=NULL;
}

void pointer_array_of_builtin_datatype(void)
{
    int** p;
    p=NULL;
    puts("pointer to the array of pointer");
    int a_size=5;
    p=(int**)malloc(a_size*sizeof(int*));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(int*));
    for (int i=0;i<a_size;i++){
        p[i]=(int*)malloc(sizeof(int));
        *p[i]=(i+1)*10;
    }
    for (int i=0;i<a_size;i++){
        printf("*p[%d]=%d\n",i,*p[i]);
    }
    for (int i=0;i<a_size;i++){
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
}

void userdefined_datatype(void)
{
    struct point* p;
    p=NULL;
    p=(struct point*)malloc(sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,sizeof(struct point));
    p->x=3;
    p->y=4;
    p->z=5;
       printf("p->x=%2lf \np->y=%2lf \np->z=%2lf\n",    /* read */ 
    p->x, p->y, p->z);
    free(p);
    p=NULL;
}

void array_of_userdefined_datatype(void)
{
    struct point* p;
    p=NULL;
    int a_size=5;
    p=(struct point*)malloc(a_size*sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,sizeof(struct point));
    for (int i=0;i<a_size;i++){
        p[i].x=(i+1)*1;
        p[i].y=(i+1)*2;
        p[i].z=(i+1)*3;
    }
     for(int i = 0; i < a_size; ++i){
        printf("p[%d]->x:%.2lf p[%d]->y:%.2lf p[%d]->z:%.2lf\n", 
                i, p[i].x, i, p[i].y, i, p[i].z); 
    } 
    free(p);
    p=NULL;
}


void pointer_array_of_userdefined_datatype(void)
{
    struct point** p;
    p=NULL;
    int a_size=5;
    p=(struct point**)malloc(a_size*sizeof(struct point*));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(struct point*));
    for (int i=0;i<a_size;i++){
        p[i]=(struct point*)malloc(sizeof(struct point));
        assert(p[i]!=NULL);
        p[i]->x=(i+1)*1;
        p[i]->y=(i+1)*2;
        p[i]->z=(i+1)*3;
    }
    for (int i=0;i<a_size;i++){
        printf("p[%d]->x:%.2lf p[%d]->y:%.2lf p[%d]->z:%.2lf\n", 
                i, p[i]->x, i, p[i]->y, i, p[i]->z);  
    }
    for (int i=0;i<a_size;i++){
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
}