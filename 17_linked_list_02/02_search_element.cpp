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
bool isPresent(node *head,int x){/// time complexity is O(n) and space complexity is O(1)
    while(head){
        if(head->data ==x){
            return true;

        }else{
            head=head->next;
        }
    }
    return false;
}
int main(){
    node *head = takeInput();
    int element;
    cin>>element;
    if(isPresent(head,element)){
        cout<<"present";
    }else{
        cout<<"not present";
    }
    return 0;
}