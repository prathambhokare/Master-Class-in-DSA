#include <iostream>
#include <string>
using namespace std;


string rotatebyone(string s){
    char a=s[0];
    for (int i=0;i<s.length()-1;i++){
        s[i]=s[i+1];
    }
    s[s.length()-1]=a;
    return s;
}

void rotation(string s1,string s2){
    while (true){
        string c=rotatebyone(s2);
        cout<<c<<"\n";
        s2=c;
        if (s1[0]==s2[0]){
            break;
        }
    }
    if (s1==s2){
            cout<<"strings are rotation of each other"<<"\n";
    }
    else{
        cout<<"strings are not rotation of each other"<<"\n";
    }
}

void rotationcheck(string s1,string s2){
    char a=s1[0];
    int index=0;
    for (int i=0;i<s2.length();i++){
        if (a==s2[i]){
            index=i;
        }
    }
    int j=index;
    cout<<"index is"<<index<<"\n";
    int c=0;
    for (int i=0;i<s1.length();i++){
        if (s1[i]!=s2[j]){
        }
        j=j+1;
        j=j%s2.length();
    }
    if (c==0){
        cout<<"strings are rotation of each other"<<"\n";
    }
    else{
        cout<<"strings are not rotation of each other"<<"\n";
    }
}
int main(){
    //rotation("abcd","dbac");
    rotationcheck("abcd","dabc");
    return 0;
}