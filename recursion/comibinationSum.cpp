#include <iostream>
#include <string>
#include <vector>
using namespace std;


void combinationSum(int index,vector<int> arr,vector<int> ans,int &target){
    if (index>=arr.size()){
        return;
    }





     if (target==0){
        cout<<"[ ";
        for (auto i : ans) cout<<i<<" ";
        cout<<"]\n";
        return;
     }




     if (target<0){
        return;
     }



    ans.push_back(arr[index]);
    target=target-arr[index];
    combinationSum(index,arr,ans,target);

    ans.pop_back();
    target=target+arr[index];
    combinationSum(index+1,arr,ans,target);
}

int main(){
    vector<int> arr={1,2,3,4};
    vector<int> ans;
    int target=4;
    combinationSum(0,arr,ans,target);
    return 0;
}