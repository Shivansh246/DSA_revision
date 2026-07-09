#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BTnode{
    public:
    T data;
    BTnode *left;
    BTnode *right;
    BTnode(T data){
        this->data=data;
        left = NULL;
        right = NULL;
    }
    ~BTnode(){//calls recursively like the destructor of general tree
        delete left;
        delete right;
    }
};
void printTree(BTnode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
BTnode<int> *takeInput(){
    int rootdata;
    cout<<"Enter root data: ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BTnode<int> *root = new BTnode<int>(rootdata);
    queue<BTnode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTnode<int> *f = q.front();
        q.pop();
        int leftdata;
        cout<<"Enter left data of "<<f->data<<": ";
        cin>>leftdata;
        if(leftdata!=-1){
            BTnode<int> *leftnode = new BTnode<int>(leftdata);
            q.push(leftnode);
            f->left = leftnode;
        }
        int rightdata;
        cout<<"Enter right data of "<<f->data<<": ";
        cin>>rightdata;
        if(rightdata!=-1){
            BTnode<int> *rightnode = new BTnode<int>(rightdata);
            q.push(rightnode);
            f->right = rightnode;
        }
    }
    return root;
}
bool helper(BTnode<int> *leftTree,BTnode<int> *rightTree){
    if(leftTree==NULL && rightTree !=NULL){
        return false;
    }
    if(rightTree==NULL && leftTree!=NULL){
        return false;
    }
    if(leftTree==NULL && rightTree == NULL){
        return true;
    }
    if(rightTree->data !=leftTree->data){
        return false;
    }
    return helper(leftTree->right,rightTree->left)&& helper(leftTree->left,rightTree->right); 
}
bool symmetric(BTnode<int> *root){
    /*
    value of root data should be equal
    left of  left == right of right
    right of left == left of right
    */
    if(root==NULL){
        return false;
    }
    return helper(root->left,root->right);
}
int main(){
    BTnode<int> *root =takeInput();
    printTree(root);
    cout<<endl;
    if(symmetric(root)){
        cout<<"Symmetric";
    }else{
        cout<<"Not Symmetric";
    }
    delete root;
    return 0;
}