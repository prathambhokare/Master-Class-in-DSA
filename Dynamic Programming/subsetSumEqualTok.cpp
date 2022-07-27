#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool subsetSumEqualTok(int ind,int target,vector<int> arr,vector<vector<int>> &dp){
     if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumEqualTok(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumEqualTok(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}

int main(){
    vector<int> arr={1,2,3,4};
    int target=5;
    vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
    if (subsetSumEqualTok(arr.size()-1,target,arr,dp)){
        cout<<"The value is Present"<<"\n";
    }
    else{
        cout<<"The value is not present"<<"\n";
    }
    return 0;
}