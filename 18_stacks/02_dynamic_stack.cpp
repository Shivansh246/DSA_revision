#include <bits/stdc++.h>
using namespace std;
class Stack{
    int *arr;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        arr = new int[5];
        nextIndex=0;
        capacity=5;
    }
    void push(int ele){
        if(nextIndex==capacity){
            capacity*=2;
            int *newArr = new int[capacity];
            for(int i =0;i<nextIndex;i++){
                newArr[i]=arr[i];
            }
            delete []arr;
            arr = newArr;
        }
        arr[nextIndex]=ele;
        nextIndex++;
    }
    void pop(){
        if(nextIndex<1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        nextIndex--;
    }
    int top(){
        if(nextIndex<1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[nextIndex-1];
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    int size(){
        return nextIndex;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

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