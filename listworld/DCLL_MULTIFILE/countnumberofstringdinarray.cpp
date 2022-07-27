#include <iostream>
#include <string>
using namespace std;


int main(){
    char a[][6]={
        {'K','E','E','G','D','D'},
        {'E','B','D','E','B','S'},
        {'E','G','K','E','B','K'},
        {'G','E','E','E','G','E'},
        {'D','E','D','D','D','E'},
        {'D','K','G','E','E','K'}
    };
    string str;
    cout<<"Enter the string"<<"\n";
    cin>>str;
    cout<<str.length()<<"\n";
    int l=str.length();
    int countpresent=0;
    for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            /*check leftside*/
            if (j>=l-1){
                int count=0;
                int n=j;
                for (int m=0;m<l;m++){
                    if (str[m]==a[i][n--]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count==l){
                    cout<<"equals"<<"\n";
                    countpresent++;
                }
            }
            /*end of check left side*/

            /*check rightside*/
            if ((6-j)>=l){
                int count=0;
                int n=j;
                for (int m=0;m<l;m++){
                    if (str[m]==a[i][n++]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count==l){
                    cout<<"equals"<<"\n";
                    countpresent++;
                }
            }
            /*end of check right side*/

            /*check top side*/
            if (i>=l-1){
                int count=0;
                int n=i;
                for (int m=0;m<l;m++){
                    if (str[m]==a[n--][j]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count==l){
                    cout<<"equals"<<"\n";
                    countpresent++;
                }
            }
            /*end of checking top side*/

            /*check bottom side*/
            if ((6-i)>=l){
                int count=0;
                int n=i;
                for (int m=0;m<l;m++){
                    if (str[m]==a[n++][j]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count==l){
                    cout<<"equals"<<"\n";
                    countpresent++;
                }
            }
            /*end of check bottom side*/
        }
    }
    cout<<"there are "<<countpresent<<" times the "<<str<<" is present"<<"\n";
}