#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#define SUCCESS 1 

typedef int ret_t; 

struct v{
    int x;
    int y;
    int z;
};

struct f{
    int v1;
    int v2;
    int v3;
};

struct vector_v{
	struct v** p_arr; 
	size_t size; 
}; 

/*vector for vertex*/
struct vector_v* create_vector_v(); 
ret_t push_back(struct vector_v* p_vec_int, struct v* new_element); 
void show(struct vector_v* p_vec_int); 
ret_t destroy_vector_v(struct vector_v* p_vec_int); 

int main(){
    struct vector_v* vec_point=create_vector_v();
    for (int i=0;i<2;i++){
        struct v* p1=NULL;
        p1->x=2;
        p1->y=3;
        p1->z=4;
        push_back(vec_point,p1);
    }
    show(vec_point);
    return 0;
}

struct vector_v* create_vector_v(){
	struct vector_v* p_vec_int = NULL; 

	p_vec_int = (struct vector_v*)malloc(sizeof(struct vector_v)); 
	if(p_vec_int == NULL)
	{
		fprintf(stderr, "Insufficient memory\n"); 
		exit(EXIT_FAILURE); 
	}

	p_vec_int->p_arr = NULL; 
	p_vec_int->size = 0; 

	return (p_vec_int); 
}


ret_t push_back(struct vector_v* p_vec_int, struct v* new_element){
	p_vec_int->p_arr = (struct v**)realloc(p_vec_int->p_arr, (p_vec_int->size + 1)*sizeof(struct v*)); 
	assert(p_vec_int->p_arr != NULL); 
	p_vec_int->size = p_vec_int->size + 1; 
    int i=p_vec_int->size-1;
	p_vec_int->p_arr[i]=(struct v*)malloc(sizeof(struct v));
    assert(p_vec_int->p_arr[i]!=NULL);
    p_vec_int->p_arr[i]=new_element; 
	return (SUCCESS); 
}


void show(struct vector_v* p_vec_int){
	int i; 
	for(i = 0; i < p_vec_int->size; ++i)
		printf("p_vec_int->p_arr[%d]: %d %d %d\n", i, p_vec_int->p_arr[i]->x,p_vec_int->p_arr[i]->y,p_vec_int->p_arr[i]->z); 
}

ret_t destroy_vector_v(struct vector_v* p_vec_int){
	free(p_vec_int->p_arr); 
	free(p_vec_int); 
	return (SUCCESS); 
}