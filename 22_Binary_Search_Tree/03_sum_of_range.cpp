#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BTnode{
    public:
    T data;
    BTnode<T> *left;
    BTnode<T> *right;
    BTnode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTnode(){
        delete left;
        delete right;
    }
};
BTnode<int> *takeInput(){
    int data;
    cout<<"Enter root data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BTnode<int> *root=new BTnode<int>(data);
    queue<BTnode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTnode<int> *f = q.front();
        q.pop();
        int leftdata;
        cout<<"Enter left data of "<< f->data<<": ";
        cin>>leftdata;
        if(leftdata!=-1){
            BTnode<int>*leftnode = new BTnode<int>(leftdata);
            q.push(leftnode);
            f->left=leftnode;
        }
        int rightdata;
        cout<<"Enter right data of "<< f->data<<": ";
        cin>>rightdata;
        if(rightdata!=-1){
            BTnode<int>*rightnode = new BTnode<int>(rightdata);
            q.push(rightnode);
            f->right=rightnode;
        }
    }
    return root;
}
void printTree(BTnode<int> *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left){
        cout<<"L:"<<root->left->data<<" ";
    }
    if(root->right){
        cout<<"R:"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int sumOfRange(BTnode<int> *root,int L, int R){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    if(root->data>=L && root->data <=R){
        sum+=root->data;
    }
    if(root->data>L){
        sum+=sumOfRange(root->left,L,R);
    }
    if(root->data<R){
        sum+=sumOfRange(root->right,L,R);
    }
    return sum;
    /*if(root->data>=L && root->data <=R){
        sum+=root->data;
    }
    if(root->data>R){
        sum+=sumOfRange(root->left,L,R);
    }else if(root->data<L){
        sum+=sumOfRange(root->right,L,R);
    }else{
        sum+=sumOfRange(root->left,L,R)+sumOfRange(root->right,L,R);
    }*/
    return sum;
}
int main(){
    BTnode<int> *root = takeInput();
    printTree(root);
    cout<<endl<<"Sum of range: "<<sumOfRange(root,1,6);
    delete root;// 5 3 7 1 2 6 10 -1 -1 -1 -1 -1 -1 -1 -1
    return 0;
}