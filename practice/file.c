#include <stdio.h>
#include <string.h>
#define OUT    0
#define IN    1
 


unsigned countWords(char *str)
{
    int state = OUT;
    unsigned wc = 0;  // word count
 
    // Scan all characters one by one
    while (*str)
    {
        // If next character is a separator, set the
        // state as OUT
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = OUT;
 
        // If next character is not a word separator and
        // state is OUT, then set the state as IN and
        // increment word count
        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }
 
        // Move to next character
        ++str;
    }
 
    return wc;
}
 
 int main()
 {
    char str[150];
    FILE* fp;
    int state=OUT;
    fp = fopen("file.txt", "r");
    while (fgets(str,150, fp)) {
        printf("%s",&str);
        printf("\n%d\n",strlen(str));
        printf("%u",sizeof(str));
    }
    fclose(fp);
    return 0;
}