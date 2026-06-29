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
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<"-> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int len(node *head){/// time complexity is O(n) and space complexity is O(n) hence recursive one is better as its space complexity is O(1)
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
int main(){
    node *head = takeInput();
    print(head);
    int length = len(head);
    cout<<"Length = "<<length;
    return 0;
}