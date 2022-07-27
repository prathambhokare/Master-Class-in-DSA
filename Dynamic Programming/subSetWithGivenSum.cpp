#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool subsetSum(int n,vector<int> &arr,int k){
    if (n>=arr.size()){
        return false;
    }
    if (k==0){
        return true;
    }
    if (k<0){
        return false;
    }
    bool incl=subsetSum(n+1,arr,k-arr[n]);
    bool excl=subsetSum(n+1,arr,k);
    return incl || excl;
}







int main(){
    vector<int> arr={1,3,4,5};
    int k=6;
    if (subsetSum(0,arr,8)){
        cout<<"The Subset With  Given sum is present"<<"\n";
    }
    else{
        cout<<"not present"<<"\n";
    }
    return 0;
}