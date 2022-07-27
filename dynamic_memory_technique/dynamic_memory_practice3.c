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
int main(void)
{
    builtin_datatype();
    array_of_builtin_datatype();
    pointer_array_of_builtin_datatype();
    userdefined_datatype();
    array_of_userdefined_datatype();
    pointer_array_of_userdefided_datatype();
    return (0);    
}


void builtin_datatype(void)
{   short* p;
    p=NULL;
    p=(short*)malloc(sizeof(short));
    assert(p!=NULL);
    memset(p,0,sizeof(short));
    *p =500;
    printf("*P=%d\n",*p);
    free(p);
    p=NULL;
}

void array_of_builtin_datatype(void)
{
    short* p;
    p=NULL;
    int a_size=5;
    int i;
    p=(short*)malloc(a_size*sizeof(short));
    assert(p!=NULL);
    memset(p,0,sizeof(short));
    for (i=0;i<a_size;i++){
        p[i]=(i+1)*10;
    }
    for (i=0;i<a_size;i++){
        printf("p[%d]=%hd\n",i,p[i]);
    }
    free(p);
    p=NULL;
}


void pointer_array_of_builtin_datatype(void)
{
    short** p;
    p=NULL;
    int a_size=5;
    int i;
    p=(short**)malloc(a_size*sizeof(short*));
    assert(p!=NULL);
    memset(p,0,a_size*sizeof(short*));
    for (i=0;i<a_size;i++){
        p[i]=(short*)malloc(sizeof(short));
        assert(p[i]!=NULL);
        *p[i]=(i+1)*10;
    }
    for  (i=0;i<a_size;i++){
        printf("*p[%d]=%hd\n",i,*p[i]);
    }
    for (i=0;i<a_size;i++){
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
    p->x=1;
    p->y=2;
    p->z=3;
    printf("p->x=%.2lf\np->y=%.2lf\np->z%.2lf\n",p->x,p->y,p->z);
    free(p);
    p=NULL;    
}

void array_of_userdefined_datatype(void)
{
    struct point* p;
    p=NULL;
    int a_size=5;
    int i;
    p=(struct point*)malloc(a_size*sizeof(struct point));
    assert(p!=NULL);
    memset(p,0,sizeof(a_size*sizeof(struct point)));
    for (i=0;i<a_size;i++){
        p[i].x=(i+1)*1;
        p[i].y=(i+1)*2;
        p[i].z=(i+1)*3;
    }
    for (i=0;i<a_size;i++){
        printf("p[%d]->x=%.2lf\np[%d]->y=%.2lf\np[%d]->z=%.2lf\n",i,p[i].x,i,p[i].y,i,p[i].z);
    }
    free(p);
    p=NULL;
}


void pointer_array_of_userdefided_datatype(void)
{
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
}