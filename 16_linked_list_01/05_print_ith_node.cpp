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
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *n = new node(data);
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
void print_ith_node(node *head,int i){
    int j=0;
    while(head){
        if(j==i){
            cout<<head->data<<endl;
            return;
        }else{
            head=head->next;
            j++;
        }
    }
}
int length(node *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
void print_ith_node2(node *head,int i){
    if(i<0){
        cout<<"-1";
        return;
    }
    int count =0;
    while(count<i && head!=NULL){
        head=head->next;
        count++;
    }
    if(head==NULL){
        cout<<"-1";
        return;
    }
    cout<<head->data;
}
int main(){
    node *head=takeInput(); 
    print_ith_node2(head,3); ///time complexity = O(i) 
    cout<<endl;
    print_ith_node(head,3); /// time complexity = O(i), but extra variable created
    return 0;
}