#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Stack{
    T *arr;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        arr=new T[4];
        nextIndex=0;
        capacity=4;
    }
    void push(T ele){
        if(nextIndex==capacity){
            capacity*=2;
            T *newArr = new T[capacity];
            for(int i=0;i<nextIndex;i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[nextIndex] = ele;
        nextIndex++;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void pop(){
        if(isEmpty()){
            cout<<"stack undeflow"<<endl;
            return;
        }
        nextIndex--;
    }
    T top(){
        if(isEmpty()){
            cout<<"stack undeflow"<<endl;
            return 0;/// 0 translates to every data type 0 in char is null terminating character and in pointer it is NULL
        }
        return arr[nextIndex-1];
    }
    
};
int main(){
    Stack<char> s;
    s.push(100);//prints the respective ASCII character
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}