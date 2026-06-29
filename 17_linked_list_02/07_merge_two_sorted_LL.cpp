#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
node *takeInput(){
    int data;
    cin>>data;
    node *head = NULL;
    node *tail=NULL;
    while(data!=-1){
        node *n = new node(data);
        if(head==NULL){
            head=n;
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
    while(head){
        cout<<head->data<<"-> ";
        head= head->next;
    }
    cout<<"NULL"<<endl;
}
node* mergeLists(node *l1,node *l2){
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    node *head=NULL;
    if(l1->data < l2->data){
        head = l1;
        l1=l1->next;
    }else{
        head = l2;
        l2=l2->next;
    }
    node *tail = head;
    while(l1 &&l2){
        if(l1->data<l2->data){
            tail->next=l1;
            l1 = l1->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1){
        tail->next = l1;
    }else{
        tail->next = l2;
    }
    return head;

}
int main(){
    node *head1 = takeInput();
    node *head2 = takeInput();
    node * head = mergeLists(head1,head2);
    print(head);
    return 0;
}