#include <iostream>
#include <string>
#include <vector>
using namespace std;


int maximumNonAdjacentSum(int n,vector<int> &nums,vector<int> &dp){
    if (n==0){
        return nums[0];
    }
    if (n<0){
        return 0;
    }
    if (dp[n]!=-1){
        return dp[n];
    }
    int take=nums[n]+maximumNonAdjacentSum(n-2,nums,dp);
    int non_take=maximumNonAdjacentSum(n-1,nums,dp);
    return dp[n]=max(take,non_take);
}






int main(){
    int n=3;
    vector<int> v={1,2,4};
    vector<int> dp(n+1,-1);
    cout<<"the maximum adjcent sum without an adjcent element is"<<maximumNonAdjacentSum(n-1,v,dp)<<"\n";
    return 0;
}