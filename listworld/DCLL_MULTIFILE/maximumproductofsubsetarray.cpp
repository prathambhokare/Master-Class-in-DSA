#include <iostream>
#include <string>
using namespace std;


int main(){
    int n;
    cout<<"Enter the number of elements of an array"<<"\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of an array"<<"\n";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int countnegative=0;
    for (int i=0;i<n;i++){
        if (a[i]<0){
            countnegative++;
        }
        else{
            break;
        }
    }
    int maxproductsum=1;
    int termnating=0;
    cout<<"the number of negative numbers are"<<countnegative<<"\n";
    if (countnegative%2!=0){
        termnating=1;
    }
    for (int i=n-1;i>=termnating;i--){
        maxproductsum=maxproductsum*a[i];
    }
    cout<<maxproductsum<<"\n";
    return 0;
}