#include <iostream>
#include <string>
using namespace std;

template <typename T>
class stack
{
private:
   T* p_arr;
   int top;
   int size;
public:
    stack(int  _size) : p_arr(new T[_size]),size(_size),top(-1){}
    ~stack() {}
    void push(T data){
        top++;
        p_arr[top]=data;
    }
    T pop(){
        T val=0;
        if (!isempty()){
            val=p_arr[top];
            top--;
            return val;
        }
        return -1;
    }
    bool isempty(){
        if (top==-1){
            return true;
        }
        return false;
    }
    void show(){
        for (int i=0;i<=top;i++){
            cout<<"["<<p_arr[i]<<"]";
        }
        cout<<"\n";
    }
};


int main(){
    stack<int> p1(5);
    p1.push(1);
    p1.push(2);
    p1.push(3);
    p1.pop();
    p1.show();
    return 0;
}