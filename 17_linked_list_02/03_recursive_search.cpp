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
bool search(node *head,int x){///time complexity is O(n) and space complexity is also O(n) hence recursive one was better
    if(head==NULL){
        return false;
    }
    if(head->data==x){
        return true;
    }
    return search(head->next,x);
}
int main(){
    node *head = takeInput();
    int element;
    cin>>element;

    if(search(head,element)){
        cout<<"found";
    }else{
        cout<<"not found";
    }
    return 0;
}