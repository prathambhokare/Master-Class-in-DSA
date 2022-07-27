#include <iostream>
#include <string>
#include <vector>
using namespace std;


void generateSubsequnces(int index,vector<int> arr,vector<int> &ans){
    if (index>=arr.size()){
        for (int i : ans){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    ans.push_back(arr[index]);
    generateSubsequnces(index+1,arr,ans);
    ans.pop_back();
    generateSubsequnces(index+1,arr,ans);
    return;
}

int main(){
    vector<int> arr={1,2,3,4};
    vector<int> ans;
    generateSubsequnces(0,arr,ans);
    return 0;
}