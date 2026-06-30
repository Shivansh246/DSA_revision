#include <bits/stdc++.h>
using namespace std;
/*
queue-> first in first out
*/
template<typename T>
class Queue{
    T *arr;
    int firstIndex;
    int lastIndex;
    int size;
    int capacity;
    public:
    Queue(){
        arr = new T[5];
        firstIndex=-1;
        lastIndex=0;
        size=0;
        capacity=5;
    }
    Queue(int cap){
        capacity=cap;
        arr = new T[capacity];
        firstIndex=-1;
        lastIndex=0;
        size=0;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T ele){
        if(size==capacity){
            cout<<"Queue full"<<endl;
            return;
        }
        if(firstIndex==-1){
            firstIndex=0;
        }
        arr[lastIndex]=ele;
        lastIndex=(lastIndex+1)%capacity;
        size++;
    }
    T front(){
        if(size==0){
            cout<<"Queue empty"<<endl;
            return 0;
        }
        return arr[firstIndex];
    }
    void pop(){
        if(size==0){
            cout<<"Stack empty"<<endl;
            return;
        }
        firstIndex = (firstIndex+1)%capacity;
        size--;
        ///optional reset if empty
        // if(size==0){
        //     lastIndex=0;
        //     firstIndex=-1;
        // }
    }
};
int main(){
    Queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();

    cout<<q.front()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;

    q.push(60);
    q.push(70);

    q.pop();
    q.pop();

    cout<<q.front()<<endl;
    cout<<q.getsize()<<endl;
    return 0;
}