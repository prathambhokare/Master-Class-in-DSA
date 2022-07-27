#include "set.h"
#include "setserver.c"



int main(){
    struct node* p=create_set();
    add_element(p,1);
    add_element(p,2);
    add_element(p,3);
    add_element(p,4);
    return 0;
}