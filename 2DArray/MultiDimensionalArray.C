#include <stdio.h> 
#include <stdlib.h> 

typedef unsigned long long u64; 

void method1(void);
void method2(void); 
void method3(void); 
 
int main(void)
{
    method1(); 
    method2(); 
    method3(); 
    return (0); 
}

void method1(void)
{
    // using data definition statement 
    int a[3][5]; 
    int i, j; 

    // printing address of a using array like syntax 
    puts("Array Syntax:"); 
    for(i = 0; i <= 2; ++i)
        for(j = 0; j <= 4; ++j)
            printf("&a[%d][%d]:%llu\n",i, j, (u64)&a[i][j]); 
        
    puts("Pointer syntax:"); 
    for(i = 0; i <= 2; ++i)
        for(j = 0; j <= 4; ++j)    
            printf("*(a + %d) + %d = %llu\n", i, j, (u64)(*(a+i) + j)); 
}

void method2(void)
{
    int i, j; 
    int (*p)[3][5]; 
    typedef int (*array3x5_t)[3][5]; 

    p = (array3x5_t)malloc(3 * 5 * sizeof(int)); 

    puts("Array Syntax");
    for(i = 0; i <= 2; ++i)
        for(j = 0; j <= 4; ++j)
            printf("&(*p)[%d][%d] = %llu\n", i, j, (u64)&(*p)[i][j]); 

    puts("Pointer syntax"); 
    for(i = 0; i <= 2; ++i)
        for(j = 0; j <= 4; ++j)
            printf(" (*((*p) + %d) + %d) = %llu\n", i, j, (u64)((*((*p) + i) + j))); 
    free(p); 
    p = NULL; 
}

void method3(void)
{
    int** pp = 0; 
    int i, j; 
    
    pp = (int**)malloc(sizeof(intptr_t) * 5); 
    for(i = 0; i <=4; ++i)
        pp[i] = (int*)malloc(sizeof(int) * 3); 

    for(i = 0; i <= 2; ++i)
        for(j = 0; j <= 4; ++j)
            printf("&pp[%d][%d] = %llu\n", i, j, (u64)&pp[i][j]); 

    for(i = 0; i <= 2; ++i)
        free(pp[i]); 

    free(pp); 
    pp = NULL; 
}