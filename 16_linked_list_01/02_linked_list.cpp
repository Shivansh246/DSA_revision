#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int data){
        this-> data = data;
        next = NULL;
    }
};
void print(node * head){//pass by value
    node *temp = head;// better to use temp as we will have the value of head and the linked list with us
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    temp = head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void print2(node * head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    //dynamic allocation
    /*node *n3 = new node(3);
    node *n4 = new node(4);
    n3->next=n4;*/
    /*node n1(1);
    node *head = &n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    print(head);// pass by value to not change the value of head*/

    ///dyanamically
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);

    node *head = n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    print2(head);
    return 0;
}