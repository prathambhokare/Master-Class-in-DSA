#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h>

#define MAX_LINE_LEN 256 
char line[MAX_LINE_LEN];
#define typedef int ret_t

/* command line 
    # app.exe text_file_path 
    # ./app text_file_path 

    Build a vector of lines in the file 
*/ 

struct vector_line{
    char** pp_lines;//representation would be like this [[word1,word2,word3][word1,word2,word3][word1,word2,word3][......][.........]--->n numbers of line]---->this my vector of line
    size_t size;
};


struct vector_line* create_vector(){
    struct vector_line* p=NULL;
    p=(struct vector_lines*)malloc(sizeof(struct vector_line));
    assert(p !=NULL);
    memset(p,0,sizeof(struct vector_line));
    if(p == NULL)
	{
		fprintf(stderr, "Insufficient memory\n"); 
		exit(EXIT_FAILURE); 
    }
    p->pp_lines=NULL;
	p->size = 0;
    return p;
}


void  push_back(struct vector_int* p_veac_int, char new_element[MAX_LINE_LEN]){
	p_vec_int->pp_lines=(char**)realloc(p_vec_int->p_arr, (p_vec_int->size + 1)*sizeof(char*));//while pushing the element into the array the  reallacocate the memory 
	assert(p_vec_int->p_arr != NULL); 
	p_vec_int->size = p_vec_int->size + 1; 
	p_vec_int->p_arr[p_vec_int->size - 1] =new_element;
	//return (SUCCESS); 
}

int main(void){
    return (0);
}
void test(void){
    int line_len = 0; 
    char* dup_line = NULL; 

    FILE* fp = fopen("abc.txt", "r")
    assert(fp); 
  
    fgets(line, MAX_LINE_LEN, fp); 
    line_len = strlen(line); 
    dup_line = (char*)malloc(line_len + 1); 
    assert(dup_line); 
    strncpy(dup_line, line, line_len);    

    /* add new_line to the vector of lines */ 
    push_back(p_vec_line, new_line); 

    /* after reading all lines in file via fgets() */ 
    show(p_vec_line); 
    destroy_vector_lines(p_vec_line); 
    p_vec_line = NULL; 

}

/* 
pp_lines [ char* ][ char* ][ char* ][ char* ][ char* ][ char* ][ char* ]
            vector of character stores here
            c       c          c        .       .       .           .
            c       c          c 
            c       c          c 
            c       c          \0 
            c       \0
            c 
            c
            c 
            \0

size_t size; 
*/ 

void destroy_vector_lines(struct vector_line *p_vec_line)
{
    int i; 
    for(i = 0; i < p_vec_line->size; ++i)
        free(p_vec_line->pp_lines[i]); 
    free(p_vec_line->pp_lines);
    free(p_vec_line); 
}