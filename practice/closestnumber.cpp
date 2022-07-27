#include <iostream>
#include <string>
using namespace std;


int main(){
    int a[]={-20,-3916237,-357920,-3620601,7374819,-7330761,30,6246457,-6461594,266854 };
    for (int i=0;i<10;i++){
        for (int j=0;j<(10-i)-1;j++){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for (int i=0;i<10;i++){
        cout<<a[i]<<"\n";
    }
    int mindiff=276593;
    for (int i=0;i<10-1;i++){
        if ((a[i+1]-a[i])<mindiff){
            mindiff=a[i+1]-a[i];
        }
    }
    for (int i=0;i<10-1;i++){
        if ((a[i+1]-a[i])==mindiff){
            cout<<a[i]<<"  "<<a[i+1]<<"\n";
        }
    }
    cout<<"minimum difference is"<<mindiff<<"\n";
    return 0;
}