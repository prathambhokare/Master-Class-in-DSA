#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void funcprint(int n){
    if (n>0){
        funcprint(n--);
        printf("%d\n",n);
    }
}
int main(){
    funcprint(4);
}