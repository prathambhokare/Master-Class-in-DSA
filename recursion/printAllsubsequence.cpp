#include <iostream>
#include <string>
#include <vector>
using namespace std;

//the printing all the subseunces
void printS(int index,vector<int> arr,vector<int> &ans){
    if (index>=arr.size()){
        cout<<"[ ";
        for (auto i : ans) cout<<i<<" ";
        cout<<"]\n";
        return;
    }

    //the taking item
    ans.push_back(arr[index]);
    printS(index+1,arr,ans);

    //the not taking item
    ans.pop_back();
    printS(index+1,arr,ans);
}



//the printing all subsequences with a given sum
void printSwithGivenSum(int index,vector<int> arr,vector<int> &ans,int &sum){
    if (index>=arr.size()){
        if (sum==0){
            cout<<"[ ";
                for (auto i : ans) cout<<i<<" ";
            cout<<"]\n";
        }
        return;
    }

    ans.push_back(arr[index]);
    sum=sum-arr[index];
    printSwithGivenSum(index+1,arr,ans,sum);
    
    sum=sum+arr[index];
    ans.pop_back();
    printSwithGivenSum(index+1,arr,ans,sum);
}

//the printing couting subsequences with a given sum
int printSwithCountGivenSum(int index,vector<int> arr,vector<int> &ans,int &sum){
    if (index>=arr.size()){
        if (sum==0){
            cout<<"[ ";
                for (auto i : ans) cout<<i<<" ";
            cout<<"]\n";
            return 1;
        }
        return 0;
    }
    ans.push_back(arr[index]);
    sum=sum-arr[index];
    int take_sum=printSwithCountGivenSum(index+1,arr,ans,sum);

    sum=sum+arr[index];
    ans.pop_back();
    int non_take_sum=printSwithCountGivenSum(index+1,arr,ans,sum);

    return take_sum+non_take_sum;
}

int main(){
    vector<int> arr={1,2,3,4};
    vector<int> ans;
    //printS(0,arr,ans);
    int sum=4;
    //printSwithGivenSum(0,arr,ans,sum);
    int result=printSwithCountGivenSum(0,arr,ans,sum);
    cout<<"The result value is"<<result<<"\n";
    return 0;
}