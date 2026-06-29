#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T>*next;
    Node(T data=0){
        this->data = data;
        next = NULL;
    }
};
template<typename T>
class Stack{
    Node<T> *head;
    int size;
    public:
    Stack(){
        head=NULL;
        size=0;
    }
    void push(T ele){//adding at head
        Node<T>*temp = new Node<T>(ele);
        temp->next = head;
        head = temp;
        size++;
    }
    bool isEmpty(){
        return head==NULL;
    }
    int give_size(){
        return size;
    }
    T top(){
        if(head==NULL){
            cout<<"stack undeflow"<<endl;
            return 0;
        }
        return head->data;
    }
    void pop(){
        if(head==NULL){
            cout<<"stack undeflow"<<endl;
            return ;
        }
        Node<T> *temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;
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

    cout<<s.give_size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}