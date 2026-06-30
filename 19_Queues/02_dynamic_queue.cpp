#include <bits/stdc++.h>
using namespace std;
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
        capacity = 5;
    }  
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if(size==0){
            cout<<"Queue empty"<<endl;
            return 0;
        }
        return arr[firstIndex];
    }
    void push(T ele){
        if(size==capacity){
            T *newArr = new T[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newArr[j]=arr[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newArr[j]=arr[i];
                j++;
            }
            firstIndex=0;
            lastIndex=capacity;
            capacity*=2;
            delete []arr;
            arr=newArr;
        }
        arr[lastIndex]=ele;
        lastIndex=(lastIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }
    void pop(){
        if(size==0){
            cout<<"Queue empty"<<endl;
            return;
        }
        firstIndex=(firstIndex+1)%capacity;
        size--;
    }
};
int main(){
    Queue<int> q;
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
    cout<<endl;
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}