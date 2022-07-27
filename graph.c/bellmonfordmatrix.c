#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int n_vertex;
    printf("Enter the number of vertex\n");
    scanf("%d",&n_vertex);
    int g[n_vertex][n_vertex];
    for (int i=0;i<n_vertex;i++){
        for (int j=0;j<n_vertex;i++){
            if (i!=j){
                int choice;
                printf("Enter the your choice\n");
                printf("1 for if edge exist\n");
                printf("2 for edge is ot exist\n");
                scanf("%d",&choice);
                if (choice==1){
                    scanf("%d",&g[i][j]);
                }
                else{
                    continue;
                }
            }
        }
    }
    return 0;
}