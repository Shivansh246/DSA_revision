#include <bits/stdc++.h>
using namespace std;
class Stack{
    vector <int> v;
    int nextIndex;
    public:
    Stack(){
        nextIndex=0;
    }
    void push(int ele){
        v.push_back(ele);
        nextIndex++;
    }
    int top(){
        if(nextIndex<1){
            cout<<"Stack Undeflow"<<endl;
            return -1;
        }
        return v[nextIndex-1];
    }
    int size(){
        return nextIndex;
    }
    void pop(){
        if(nextIndex<1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        nextIndex--;
    }
    bool isEmpty(){
        return nextIndex==0;
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