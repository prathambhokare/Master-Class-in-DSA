#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(){
    char** p;
    p=NULL;
    p=(char**)malloc(5*sizeof(char*));
    assert(p!=NULL);
    memset(p,0,5*sizeof(char*));
    FILE* fp;
    fp = fopen("file.txt", "r");
        char str[150];
        int i=0;
        while (fgets(str,150, fp)) {
        printf("%s",&str);
        printf("\n%d\n",strlen(str));
        printf("%u",sizeof(str));
        p[i]=(char*)malloc(256*sizeof(char));
        assert(p[i]!=NULL);
        p[i]=str;
        i++;
    }
    fclose(fp);
    }
    for (int j=0;j<i;j++){
        printf("%s\n",p[j]);
        free(p[ij]);
    }
    free(p);
    return 0;
}