#include <bits/stdc++.h>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data = data;
        next=NULL;
    }
};
template<typename T>
class Queue{
    node<T> *head;
    node<T> *tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void push(T ele){
        node<T> *n = new node<T>(ele);
        if(head==NULL){
            head=n;
            tail=n;
            size++;
            return;
        }
        tail->next=n;
        tail=n;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Queue empty"<<endl;
            return;
        }
        node<T>*temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if(head==NULL){
            cout<<"Queue empty"<<endl;
            return 0;
        }
        return head->data;
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
    // cout<<endl;
    // while(!q.isEmpty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
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
    cout<<endl;
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}