#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define hash(n,k) ((n)%(k))
typedef int status_t

struct hash{
    vector<int> v;
};



void createHash(int bucket_size);
status_t add(struct hash h[],int value,int k);
void display(struct hash h[],int k);
