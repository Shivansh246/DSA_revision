#include <iostream>
using namespace std;
class Stack{
    int *arr;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        arr=new int[4];
        nextIndex=0;
        capacity=4;
    }
    Stack(int cap){
        arr = new int[cap];
        nextIndex=0;
        capacity=cap;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int x){
        if(nextIndex==capacity){
            cout<<"Stack Full"<<endl;
            return;
        }
        arr[nextIndex]=x;
        nextIndex++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return;
        }
        nextIndex--;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return -1;
        }
        return arr[nextIndex-1];
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