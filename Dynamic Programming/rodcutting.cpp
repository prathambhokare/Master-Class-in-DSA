#include <iostream>
#include <string>
#include <vector>
using namespace std;


int maximize_price(int n,int price[]){
    int max_cost=max_value;
    for (int i=1;i<=n;i++){
        int max_price=price[i];
        int j=1;
        int k=i-1;
        while (j<=k){
            int cut_price=price[j]+price[k];
            j++;
            k--;
            max_price=max(max_price,cut_price);
        }
        max_cost=max(max_cost,max_price);
    }
    return max_cost;
}



int max_price[10];
void maximize_pricerecursive(int i,int price[]){
    if (i<1){
        return;
    }
    int max_price=price[i];
    int j=1;/
    int k=i-1;
    while (j<=k){
        int cut_price=price[j]+price[k];
        j++;
        k--;
        max_price=max(max_price,cut_price);
    }
    max_price[i]=max_price;
    maximize_pricerecursive(i--,price,max_cost);
}



int main(){
    return 0;
}