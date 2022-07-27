#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){
    char** pp = NULL; 
    int a_size = 5; 
    int i; 
    puts("array_of_pointers_built_in_intype"); 
    pp = (int**)malloc(a_size * sizeof(char*)); 
    assert(pp != NULL);
    memset(pp, 0, a_size * sizeof(char*));
    for(i = 0; i < a_size; ++i)
    {
        pp[i] = (char*)malloc(256*sizeof(char));
        memset(pp[i],0,256*sizeof(char)); 
        assert(pp[i] != NULL);
        *pp[i] ='abcd'; 
    }
    for(i = 0; i < a_size; ++i)
    {
        free(pp[i]); 
        pp[i] = NULL; 
    }

    free(pp); 
    pp = NULL; 
    return 0;
}