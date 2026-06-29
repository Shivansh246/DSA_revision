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
node *recursive_merge(node *l1,node *l2){
    if(l1==NULL){
        return l2;
    }
    if(l2 == NULL){
        return l2;
    }
    node *newhead = NULL;
    if(l1->data <l2->data){
        newhead = l1;
        newhead->next = recursive_merge(l1->next,l2);
    }else{
        newhead = l2;
        newhead->next = recursive_merge(l1,l2->next);
    }
    return newhead;
}
int main(){
    node *head1 = takeInput();
    node *head2 = takeInput();
    node *head = recursive_merge(head1,head2);
    print(head);
    return 0;
}