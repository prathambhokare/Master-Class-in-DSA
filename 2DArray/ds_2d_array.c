#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

void array2d(int m, int n); 
void array3d(int m, int n, int k); 

int main(void)
{
    int m, n, k; 

    printf("Enter m:"); 
    scanf("%d", &m); 
    printf("Enter n:"); 
    scanf("%d", &n); 
    
    array2d(m, n); 

    printf("Enter m:"); 
    scanf("%d", &m); 
    printf("Enter n:"); 
    scanf("%d", &n); 
    printf("Enter k:"); 
    scanf("%d", &k); 
    
    array3d(m, n, k); 

    exit(0); 
}

void array2d(int m, int n)
{
    int i, j; 
    assert(m && n); 
    int* p = (int*)malloc(sizeof(int) * m * n); 

    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            *(p + i * n + j) = (i+j); 

    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            printf("*(p + %d * n + %d):%d\n", i, j, *(p + i * n + j)); 

    free(p); 
    p = NULL; 
}


void array3d(int m, int n, int q)
{
    int* p = NULL; 
    int i, j, k; 
    assert(m && n && q); 

    p = (int*)malloc(sizeof(int) * m * n * q); 

    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            for(k = 0; k < q; ++k)
                *(p + i * n * q + j * n + k) = (i + j + k); 

    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            for(k = 0; k < q; ++k)
                printf("*(p + %d * n * q + %d * n + %d):%d\n", i, j, k, 
                        *(p + i * n * q + j * n + k)); 

    free(p); 
    p = NULL; 
}