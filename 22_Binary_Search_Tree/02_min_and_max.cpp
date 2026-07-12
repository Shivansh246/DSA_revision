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
int findMin(BTnode<int> *root){
    if(root==NULL){
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
int findMax(BTnode<int>*root){
    if(root==NULL){
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}
int main(){
    BTnode<int> *root = takeInput();
    printTree(root);
    cout<<endl<<"Min: "<<findMin(root)<<endl;
    cout<<"Max: "<<findMax(root)<<endl;
    delete root;
    return 0;// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
}