#include <iostream>
#include <string>
#include <vector>
using namespace std;


int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (m,0));
    for (int i=0;i<m;i++){
        dp[0][i]=arr[0][i];
    }
    for (int j=0;j<n;j++){
        dp[j][0]=arr[j][0];
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if (arr[i][j]==0) continue;
            dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
        }
    }
    int sum=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            sum=sum+dp[i][j];
        }
    }
    return sum;
}


int main(){
    int n=3;
    int m=4;
    vector<vector<int>> arr(n,vector<int>(m,0));
    arr={
        {0,1,1,0},
        {1,1,1,0},
        {0,0,1,0}};
    cout<<countSquares(n,m,arr);
    return 0;
}