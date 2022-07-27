#include <iostream>
#include <string>
using namespace std;


int main(){
    int n;
    cout<<"Enter the elements of an array"<<"\n";
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cout<<"Enter the number of operations to perform"<<"\n";
    cin>>k;
    int countneg=0;
    for (int i=0;i<n;i++){
        if (a[i]<0){
            countneg++;
        }
    }
    int remoperation=k-countneg;
    int actualoperation=remoperation%2;
    int maxsum=0;
    int min=a[0];
    for (int i=0;i<n;i++){
        if (min>a[i]){
            min=a[i];
        }
    }
    cout<<"minimum is"<<min<<"\n";
    if (actualoperation==0){
        for (int i=0;i<n;i++){
            maxsum=maxsum+abs(a[i]);
        }
    }
    else{
         for (int i=0;i<n;i++){
            if (a[i]!=min){
                maxsum=maxsum+abs(a[i]);
            }
            else{
                maxsum=maxsum+a[i];
            }
        }
    }
    cout<<maxsum<<"\n";
}