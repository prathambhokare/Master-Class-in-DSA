#include <iostream>
#include <string>
#include <vector>
using namespace std;


int countSubsetWithSumEqualTok(int index,int target,vector<int> arr,vector<vector<int>> &dp){
        if (target==0){
            return 1;
        }
        if(index == 0){
            return arr[index] == target;
        }
        if( dp[index][target]  != -1){
            return  dp[index][target] ;
        }
        int notPick = countSubsetWithSumEqualTok(index - 1 , target ,arr , dp);
        int pick = 0;
        if(target >= arr[index]){
            pick = countSubsetWithSumEqualTok( index - 1, target - arr[index], arr ,dp);
        }
        return dp[index][target] =  pick + notPick;
}


int main(){
    vector<int> arr={1,2,3,4};
    int target=4;
    int ans=0;
    vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
    ans=countSubsetWithSumEqualTok(arr.size()-1,target,arr,dp);
    cout<<"the value of a ans is"<<ans<<"\n";
    return 0;
}


/*
int solveRec(int ind,int tar,vector<int>&arr){
    if(tar==0) return 1;
    if(ind==0) return arr[ind]==tar;
    
     int notTake=solveRec(ind-1,tar,arr);
    int take=0;
    if(arr[ind]<=tar) take=solveRec(ind-1,tar-arr[ind],arr);
    
    return (take+notTake);
}
int solveMemo(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp){
    if(tar==0) return 1;
    if(ind==0) return arr[ind]==tar;
    if(dp[ind][tar]!=-1) return dp[ind][tar];
     int notTake=solveMemo(ind-1,tar,arr,dp);
    int take=0;
    if(arr[ind]<=tar) take=solveMemo(ind-1,tar-arr[ind],arr,dp);
    
    return dp[ind][tar]=(take+notTake);
}
int solveTabu(vector<int>&nums,int tar){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(nums[0]<=tar) dp[0][nums[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int target=1;target<=tar;target++){
            int notTake=dp[i-1][target];
            int take=0;
            if(nums[i]<=target) take=dp[i-1][target-nums[i]];
    
             dp[i][target]=(take+notTake);
        }
    }
    
    return dp[n-1][tar];
}
int solveTabuSo(vector<int>&nums,int tar){
    int n=nums.size();
    vector<int>prev(tar+1,0),cur(tar+1,0);
    
        prev[0]=cur[0]=1;
    
    if(nums[0]<=tar) prev[nums[0]]=cur[nums[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int target=1;target<=tar;target++){
            int notTake=prev[target];
            int take=0;
            if(nums[i]<=target) take=prev[target-nums[i]];
    
             cur[target]=(take+notTake);
        }
        prev=cur;
    }
    
    return prev[tar];
}*/