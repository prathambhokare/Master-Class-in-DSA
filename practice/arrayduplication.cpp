#include <iostream>
#include <string>
using namespace std;


int main(){
    int n;
    cout<<"Enter the size of the array"<<"\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of an array"<<"\n";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    int i=0;
    int val=i;
    int first=i;
    while (i<n){
        first=val;
        int countequal=0;
        for (int j=i;j<n;j++){
            if (a[i]==a[j]){
                countequal=countequal+1;
            }
            else{
                break;
            }
        }
        val=i+countequal;
        cout<<"[   "<<"<"<<first<<">   "<<a[i]<<"   <"<<val<<">"<<"   ]"<<"\n";
        i=i+countequal;
    }
    return 0;
}