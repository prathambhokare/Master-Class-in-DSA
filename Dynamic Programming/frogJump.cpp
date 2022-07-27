#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
using namespace std;

int frogJump(int n,vector<int> heights){
    if (n==0){
        return 0;
    }

    int left=abs(heights[n]-heights[n-1])+frogJump(n-1,heights);
    int right=INT_MAX;
    if (n>1)
        right=abs(heights[n]-heights[n-2])+frogJump(n-2,heights);
    return min(left,right);
}


int frogJumpWihDP(int n,vector<int> heights,vector<int> &dp){
    if (n==0){
        return 0;
    }


    if (dp[n]!=-1) return dp[n];

    int left=abs(heights[n]-heights[n-1])+frogJump(n-1,heights);
    int right=INT_MAX;
    if (n>1)
        right=abs(heights[n]-heights[n-2])+frogJump(n-2,heights);
    return dp[n]=min(left,right);
}


int frogkJumpWihDP(int n,vector<int> heights,int k,vector<int> &dp){
    if (n==0){
        return 0;
    }


    if (dp[n]!=-1) return dp[n];
    int mini=INT_MAX;
    for (int i=1;i<=k;i++){
        if ((n-k)>=0){
            mini=min(mini,abs(heights[n]-heights[n-i])+frogJump(n-1,heights));
        } 
    }
    return dp[n]=mini;
}

int main(){
    int n=4;
    //vector<int> heights={10,20,30,10};
    //cout<<"The minimum energy lost by frog to jump from 1st stair to nth stair"<<frogJump(n-1,heights)<<"\n";
    //vector<int> heights={10,20,30,10};
    //vector<int> dp(n+1,-1);
    //cout<<"The minimum energy lost by frog to jump from 1st stair to nth stair"<<frogJumpWihDP(n-1,heights,dp)<<"\n";
    vector<int> heights={30,10,60 , 10 , 60 , 50};
    n=heights.size();
    int k=2;
    vector<int> dp(n,-1);
    cout<<"The minimum energy lost by frog to jump from 1st stair to nth stair"<<frogkJumpWihDP(n-1,heights,k,dp)<<"\n";
    return 0;
}