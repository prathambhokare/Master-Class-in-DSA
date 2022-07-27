#include <iostream>
#include <string>
using namespace std;


int main(){
    int n;
    cout<<"Enter the size of the array"<<"\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of an array"<<"\n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=0;
    for (int i=0;i<n;i++){
        if (arr[i]>max){
            max=arr[i];
        }
        int sum=arr[i];
        for (int j=i+1;j<n;j++){
            cout<<"maximum number is"<<max<<"the value of sum is"<<sum<<"value of j at is"<<arr[j]<<"\n";
            cout<<"max value is"<<max<<"\n";
            if ((sum^arr[j])>max){
                max=sum^arr[i];
            }
            sum=sum+arr[j];
        }
    }
    cout<<max<<"\n";
    return 0;
}