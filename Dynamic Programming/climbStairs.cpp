#include <iostream>
#include <string>
#include <vector>
using namespace std;


int countWay(int n,vector<int> &dp){
    if (n==0) return 1;
    if (n==1) return 1;
    if (dp[n]!=-1) return dp[n];
    int left=countWay(n-1,dp);
    int right=countWay(n-2,dp);
    return dp[n]=left+right;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    countWay(n,dp);
    cout<<"The way to climb stairs"<<dp[n]<<"\n";
    return 0;
}