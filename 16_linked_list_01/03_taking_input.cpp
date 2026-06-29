#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data):data(data){
        next=NULL;
    }
};
node * takeInput(){///inserting at tail
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data!=-1){
        node *n=new node(data);/// node created dynamicaly because statically created node will get deleted after the respective iteration of the while loop ends
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;///tail=tail->next
        }
        cin>>data;
    }
    return head;
}
node * takeInput2(){///inserting at head
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data!=-1){
        node *n=new node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            n->next=head;
            head=n;
        }
        cin>>data;
    }
    return head;
}
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<endl;
}
int main(){
    node * head = takeInput();//inserting at tail
    node * head2 = takeInput2();//inserting at head

    print(head);
    print(head2);
    return 0;
}