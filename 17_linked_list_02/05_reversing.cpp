#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
node *takeInput(){
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *n=new node(data);
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            tail->next=n;
            tail = n;
        }
        cin>>data;
    } 
    return head;
}
 node *takeInput2Reverse(){
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *n=new node(data);
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            n->next = head;
            head = n; 
        }
        cin>>data;
    } 
    return head;
 }
 void print(node *head){
     while(head!=NULL){
         cout<<head->data<<"-> ";
         head=head->next;
        }
        cout<<"NULL"<<endl;
}
node *reverse(node * head){
    node *curr = head;
    node *prev = NULL;
    while(curr!=NULL){
        node *n = curr->next;
        curr->next = prev;

        prev = curr;
        curr=n;
    }
    return prev;
}
int main(){
    /*one way to reverse is by taking input through tail i.e.:
    node *head = takeInput2Reverse();*/
    node *head=takeInput();
    node *reversed = reverse(head);
    print(reversed);
    return 0;
}