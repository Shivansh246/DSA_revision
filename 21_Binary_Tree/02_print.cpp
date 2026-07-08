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
void print2(BTnode<int> *root){
    if(root == NULL){
        return;//// base case as there is no children.size() to return for the base case
    }
    cout<<root->data<<" ";
    print2(root->left);
    print2(root->right);
}
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
int main(){
    BTnode<int> *root = new BTnode<int>(1);
    BTnode<int> *n1 = new BTnode<int>(2);
    BTnode<int> *n2 = new BTnode<int>(3);
    root->left = n1;
    root->right = n2;
    //print2(root)
    printTree(root);
    delete root;
    return 0;
}