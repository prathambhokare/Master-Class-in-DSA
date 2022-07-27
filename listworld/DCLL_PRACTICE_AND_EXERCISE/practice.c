/* 
    Part 1: Write header file twice with commenting 
    Part 2: Write all auxillary functions with commenting once 
            and without commenting 4 times. 
            Make a file for each auxillary function 
            where in you will write it five times. 
    Part 3: Interface function implementation and its unit test in main 
    Part 4: Implement all interface routines WITHOUT ANY HELPER ROUTINE 

    EXERCISE : WORD_FINDER : LINKED LIST 
*/ 

void generic_insert(node_t* p_beg, node_t* p_mid, node_t_ p_end)
{
    p_mid->next = p_end;    /* comment */ 
    p_mid->prev = p_beg;    /* comment */ 
    p_beg->next = p_mid;    /* comment */ 
    p_end->prev = p_mid;    /* comment */ 
}

/* Get a text editor without any auto completion support */ 
void* xmalloc(size_t nr_bytes)
{
    void* p = NULL; 
    p = malloc(nr_bytes); 
    if(p == NULL)
    {
        fprintf(stderr, "Fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
}

int reverse_list(list_t* p_list)
{
    node_t* p_run, *p_run_prev, *p_prev_orig; 

    p_run = p_list->prev->prev;  
    p_prev_orig = p_list->prev; 

    while(p_run != p_list)
    {
        p_run_prev = p_run->prev; 
        generic_insert(p_list->prev, p_run, p_list); 
    }
    p_list->next = p_prev_orig; 
    p_prev_orig->next = p_list; 
    
    return (SUCCESS); 
}

/////////////////////////////////////////////////////
p_run->p_word->p_str 

p_run_next = p_run->next; 
free(p_run->p_word->p_str); 
free(p_word); 
free(p_run); 
/////////////////////////////////////////////////////