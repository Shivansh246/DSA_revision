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
node *findmid(node *head){
    if(head==NULL){
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    // while(head!=NULL){
    //     if(fast==NULL){
    //         return slow;
    //     }else if(fast->next==NULL){
    //         return slow->next;
    //     }
    //     fast=fast->next->next;
    //     slow = slow->next;
    //     head=head->next;
    // }
    // return head;

    //          OR
    while(fast && fast->next){
        slow = slow->next;
        fast=fast->next->next;
    }
    if(fast==NULL){//odd as it also means fast->next does not exist
        return slow;
    }
    return slow->next;//even
}
int main(){
    node *head = takeInput();
    /*first method to find mid:
    find length and traverse up to length/2*/

    /*second method
    take a slow pointer and a fast pointer
    the slow pointer will move one step at a time
    the fast pointer will move two steps at a time
    for odd number of terms when fast reaches NULL slow is at the mid
    for even number of terms when fast->next reaches NULL slow reaches 1 step behind the
    mid(considering required mid is the second one of the two in the middle)
    */
    node * req = findmid(head);
    cout<<req->data;
    return 0;
}