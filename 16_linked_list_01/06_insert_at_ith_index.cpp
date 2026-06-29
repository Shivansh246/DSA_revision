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
    node* head=NULL;
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
void print(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
node *insert(node *head,int i ,int x){
    if(!head || i<0){
        return head;
    }
    node *n=new node(x);
    if(i==0){   
        n->next=head;
        head=n;
        return head;
    }
    int j=1;
    node *temp=head;
    while(j<=i-1 && temp!=NULL){
        temp=temp->next;
        j++;
    }
    if(temp){
        n->next=temp->next;
        temp->next=n;
        return head;
    }
    return head;
}

int main(){
    node *head=takeInput();
    print(head);
    int i,x;
    cin>>i>>x;
    head=insert(head,i,x);
    cout<<endl;
    print(head);
    return 0;
}