#include <bits/stdc++.h>
using namespace std;




int main()
{
    //write your code here
    int n;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int i=0;
    int j=0;
    int sum=a[i][j];
    cout<<sum<<"\n";
    while (i<n-1 && j<n-1){
            cout<<a[i][j+1]<<"\n";
            cout<<a[i+1][j]<<"\n";
            if ((a[i][j+1]>a[i+1][j])){
                sum=sum+a[i+1][j];
                i=i+1;
                j=j;
            }
            else{
                sum=sum+a[i][j+1];
                i=i;
                j=j+1;
            }
            cout<<sum<<"\n";
    }
    cout<<"i is"<<i<<"\n";
    cout<<"j is"<<j<<"\n";
    int m1=i+1;
    int n1=j+1;
    if (i==n-1 && j==0){
        cout<<"i am here"<<"\n";
        int k=0;
        while(k!=(n-1)-1){
            sum=sum+a[i][n1];
            cout<<a[i][n1]<<"\n";
            n1=n1+1;
            k=k+1;
        }
    }
    if (i==0 && j==n-1){
        cout<<"i am second here"<<"\n";
        int k=0;
        while(k!=(n-1)-1){
            sum=sum+a[i][n1];
            cout<<a[m1][j]<<"\n";
            m1=m1+1;
            k=k+1;
        }
    }
    cout<<sum+a[n-1][n-1]<<"\n";
    return 0;
}