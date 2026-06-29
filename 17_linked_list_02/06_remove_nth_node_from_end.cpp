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
node* removeFromEnd(node *head,int k){
    node *first = head;
    node *second = head;
    // for(int i=1;i<=k;i++){// 1 2 3 4 5
    //     second = second->next;
    // }
    //     OR
    while(k--){//k times
        second = second->next;
    }
    if(second ==NULL){//removing the 1st node
        node *temp = head;
        delete temp;
        return first->next;
    }
    while(second->next!=NULL){
        first = first->next;
        second = second->next;
    }
    node *temp = first->next;
    first->next=first->next->next;
    delete temp;
    return head;
}
int main(){
    node *head=takeInput();
    /*
    method 1 : find length 
    find (l - n + 1 )th node from the starting
    do the required calculation
    but we are traversing 2 times
    */
    /*
    method - 2:
    take two pointers both at head
    the second pointer will move k jumps 
    then both the pointers will move simultaneously till 2nd pointer reaches the last node
    when 2nd pointer is at last node the first pointer is at one node behind the required node
    the position of first is the desired position as we have to delete the node  
    */
   print(head);
   node *newnode = removeFromEnd(head,3);
   print(newnode);
    return 0;
}