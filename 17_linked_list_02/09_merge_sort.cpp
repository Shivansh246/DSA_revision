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
node *merge2lists(node *a,node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    node *head=NULL;
    node *tail=NULL;
    if(a->data < b->data){
        head=a;
        tail = a;
        a = a->next;
    }else{
        head = b;
        tail = b;
        b = b->next;
    }
    while(a && b){
        if(a->data < b->data){
            tail->next=a;
            tail=a;
            a=a->next;
        }else{
            tail -> next = b;
            tail = b;
            b= b->next;
        }
    }
    if(a == NULL){
        tail->next = b;
    }
    if(b==NULL){
        tail->next = a;
    }
    return head;
}
node * mergeSort(node *head){
    /*
    break the list in two parts by finding the mid
    to find mid use slow and fast pointer approach
    call recursion on the two list such that it returns two sorted lists
    merge the rwo sorted lists
    */
    if(head ==NULL || head->next==NULL){// zero or no element remains
        return head;
    }
    ///find mid and break list in two parts
    node *slow = head;
    node *fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast = fast->next->next;
    }
    ///this while loop will return mid pointer if no of elements are odd and left of mid elements if no of elements are even
    node *nexthead=slow->next;
    slow->next=NULL;

    ///calling recursion
    node * a = mergeSort(head);
    node *b=mergeSort(nexthead);

    ///sorting the arrays
    head = merge2lists(a,b);
    return head;

}
int main(){
    node *head = takeInput();
    head=mergeSort(head);
    print(head);
    return 0;
}