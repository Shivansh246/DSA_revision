#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        next=NULL;
    }
};
node *takeInput(){
    int data ;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *n=new node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
        cin>>data;
    }
    return head;
}
void print(node * head){
    while(head!=NULL){
        cout<<head->data<<"-> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
/* with memory leak
node *delete_ith_node(node * head,int i){
    if(i<0){
        return head;
    }
    node *temp=head;
    if(i==0 && head!=NULL){
        return head->next;
    }
    int count = 0;// 0 1 2
    while(count<i-1 &&temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL && temp->next!=NULL){
        temp->next = temp->next->next;
    }
    return head;
}*/

///without memory leak
node *delete_ith_node(node * head,int i){
    if(i<0){
        return head;
    }
    node *temp=head;
    if(i==0 && head!=NULL){
        node * newHead = head->next;
        head->next=NULL;//isolation of node
        delete head;
        return newHead;
    }
    int count = 0;// 0 1 2
    while(count<i-1 &&temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL && temp->next!=NULL){
        node *todelete=temp->next;
        temp->next = todelete->next;
        todelete->next=NULL;//isolation
        delete todelete;
    }
    return head;
}
int main(){
    node *head=takeInput();
    print(head);
    head=delete_ith_node(head,0);
    print(head);
    return 0;
}