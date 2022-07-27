#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SUCCESS 1 

typedef int ret_t; 

struct vector_int{
	char** p_arr;//create an array 
	size_t size; 
}; 

struct vector_int* create_vector_int(); 
ret_t push_back(struct vector_int* p_vec_int, int new_element); 
void show(struct vector_int* p_vec_int); 
ret_t destroy_vector_int(struct vector_int* p_vec_int); 

int main(){
	struct vector_int** p_vec_int = NULL; 
	int i; 
	ret_t ret; 

	p_vec_int = create_vector_int(); 
	for(i = 0; i < 10; ++i)
		push_back(p_vec_int, (i+1) * 10); 
	show(p_vec_int); 
	ret = destroy_vector_int(p_vec_int); 
	assert(ret == SUCCESS); 
	p_vec_int = NULL; 
	return (EXIT_SUCCESS); 
}

struct vector_int* create_vector_int(){
	struct vector_int* p_vec_int = NULL; 

	p_vec_int = (struct vector_int*)malloc(sizeof(struct vector_int)); 
	if(p_vec_int == NULL)
	{
		fprintf(stderr, "Insufficient memory\n"); 
		exit(EXIT_FAILURE); 
	}

	p_vec_int->p_arr = NULL; 
	p_vec_int->size = 0; 

	return (p_vec_int); 
}

ret_t push_back(struct vector_int* p_vec_int, int new_element){
	p_vec_int->p_arr = (int*)realloc(p_vec_int->p_arr, (p_vec_int->size + 1)*sizeof(int));//while pushing the element into the array the  reallacocate the memory 
	assert(p_vec_int->p_arr != NULL); 
	p_vec_int->size = p_vec_int->size + 1; 
	p_vec_int->p_arr[p_vec_int->size - 1] = new_element; 
	return (SUCCESS); 
}

void show(struct vector_int* p_vec_int){
	int i; 
	for(i = 0; i < p_vec_int->size; ++i)
		printf("p_vec_int->p_arr[%d]:%d\n", i, p_vec_int->p_arr[i]); 
}

ret_t destroy_vector_int(struct vector_int* p_vec_int){
	free(p_vec_int->p_arr); 
	free(p_vec_int); 
	return (SUCCESS); 
}