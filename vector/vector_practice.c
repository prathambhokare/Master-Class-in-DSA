#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <assert.h>

#define SUCCESS 1 

typedef int ret_t; 

struct vector_int{
	char** p_arr; 
	size_t size; 
}; 

struct vector_int* create_vector_int(); 
ret_t push_back(struct vector_int* p_vec_int, char new_element); 
void show(struct vector_int* p_vec_int); 
ret_t destroy_vector_int(struct vector_int* p_vec_int); 

int main(){
	struct vector_int* p_vec_int = NULL; 
	int i; 
	ret_t ret; 

	p_vec_int = create_vector_int(); 
	for(i = 0; i < 10; ++i){
	    char c[25]='abcd';
		push_back(p_vec_int,&c);
	} 
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

ret_t push_back(struct vector_int* p_vec_int,char new_element[256]){
	p_vec_int->p_arr = (char**)realloc(p_vec_int->p_arr, (p_vec_int->size + 1)*sizeof(char*)); 
	assert(p_vec_int->p_arr != NULL);
	p_vec_int->size = p_vec_int->size + 1;
	int i=0; 
	while (new_element!='\0'){
		p_vec_int->p_arr[p_vec_int->size - 1][i]=(char*)realloc((i+1)*sizeof(char))
		p_vec_int->p_arr[p_vec_int->size - 1][i] = new_element[i];
		i++;
	}
	return (SUCCESS); 
}

void show(struct vector_int* p_vec_int){
	int i; 
	for(i = 0; i < p_vec_int->size; ++i)
		printf("p_vec_int->p_arr[%d]:%s\n", i, p_vec_int->p_arr[i]); 
}

ret_t destroy_vector_int(struct vector_int* p_vec_int){
	free(p_vec_int->p_arr); 
	free(p_vec_int); 
	return (SUCCESS); 
}