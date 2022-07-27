#include <iostream>
#include <string>
using namespace std;


int main(){
    int (*p)[5];//p is pointer to array of 5 integer
    int *a[5];//a is array 5 of pinter to integer
    *p[0]=5;
    return 0;
}