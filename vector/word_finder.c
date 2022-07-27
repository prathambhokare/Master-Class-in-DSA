#include <stdio.h> 
#include <stdlib.h> 

struct word{
    char* word; 
    int line_number; 
    int word_number; 
}; 

struct vector_of_words
{
    struct word** pp_words; 
    size_t size; 
}; 

/* IMPLEMENT */ 
struct vector_of_words* create_vector_of_words(); 
void push_back(struct vector_of_words* p_vec, struct word* p_new_word); 
void find_and_print(struct vector_of_words* p_vec, char* word); 
void destroy_vector_of_words(struct vector_of_words* p_vec); 

#define LINE_LEN 1024 
#define OUT 1 
#define IN 2 
char line[LINE_LEN]; 

struct vector_of_words* build_vector_of_words(const char* path_name){
    FILE* fp = NULL; 
    struct vector_of_words* p_vec = NULL; 

    int i; 
    int start_index; 
    int end_index; 
    int word_len; 
    int line_number_in_file; 
    int word_number_in_line; 
    char* new_word; 

    fp = fopen(path_name, "r"); 
    assert(fp); 

    p_vec = (struct vector_of_words*)malloc(sizeof(struct vector_of_words)); 
    assert(p_vec); 

    memset(line, 0, LINE_LEN); 
    while(fgets(line, LINE_LEN, fp) != NULL)
    {
        ++line_number_in_file; 
        /* convert line into the line containing chars & digits only */ 
        for(i = 0; i < strlen(line); ++i)
            if(!isalpha(line[i]) && !isdigit(line[i]))
                line[i] = '\0'; 

        state = OUT; 
        for(i = 0; i < strlen(line); ++i)
        {
            word_number_in_line = 0; 
            /*  OUT -> IN 
                start_index = i; 
                ++word_number_in_line 

                IN -> OUT 
                end_index = i 
                line[end_index] = '\0'
                word_len = end_index-start_index
                struct word* new_word = malloc(sizeof(struct word)); 
                new_word->word = malloc(word_len + 1); 
                strncpy(new_word->word, &line[start_index], word_len); 
                new_word->line_number = line_number_in_file; 
                new_word->word_number = word_number_in_line; 

                ADD NEW WORD TO VECTOR 
            */ 
        }
    }
}

/* 
# ./word_finder abc.txt int 
*/ 