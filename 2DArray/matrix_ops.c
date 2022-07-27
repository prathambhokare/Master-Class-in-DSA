#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct matrix{
    int* p;
    int row;
    int col;
};

struct matrix* getmatrixnode(){
    struct matrix* p=NULL;
    p=(struct matrix*)malloc(sizeof(struct matrix));
    if (p==NULL){
        printf("Error is occured\n");
    }
    memset(p,0,sizeof(struct matrix));
    return p;
}

struct matrix* create_matrix(int m,int n){
    struct matrix* p=getmatrixnode();
    int* a=NULL;
    a=(int*)malloc(m*n*sizeof(int));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            int value;
            printf("Enter the value of the %d and %d\n",i,j);
            scanf("%d",&value);
            *(a+i*n+j)=value;
        }
    }
    p->p=a;
    p->row=m;
    p->col=n;
    return p;
}



struct matrix* add_matrix(struct matrix* p1,struct matrix* p2){
    struct matrix* add=getmatrixnode();
    int* a=NULL;
    a=(int*)malloc(m*n*sizeof(int));
    for (int i=0;i<p1->row;i++){
        for (int j=0;j<p1->col;j++){
            *(a+i*n+j)=*(p1->p+i*n+j)+*(p2->p+i*n+j);
        }
    }
    add->p=a;
    add->row=p1->row;
    add->col=p1->col;
    return add;
}

struct matrix* sub_matrix(struct matrix* p1,struct matrix* p2){
    struct matrix* sub=getmatrixnode();
    int* a=NULL;
    a=(int*)malloc(m*n*sizeof(int));
    for (int i=0;i<p1->row;i++){
        for (int j=0;j<p1->col;j++){
            *(a+i*n+j)=*(p1->p+i*n+j)-*(p2->p+i*n+j);
        }
    }
    sub->p=a;
    sub->row=p1->row;
    sub->col=p1->col;
    return add;
}

struct matrix* multiplication(struct matrix* p1,struct matrix* p2){
    struct matrix* mul=
    int* a=NULL;
    if (p1->col==p2->row){
        for (int i=0;i<p1->row;i++){
            for (int j=0;j<p1->row;j++){
                *(a+n*j+i)=multiply_col(p2,(p1+i),j);
            }
        }
    }
}
int main(){
    return 0;
}