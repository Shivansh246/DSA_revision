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
    ~BTnode(){
        delete left;
        delete right;
    }

};
BTnode<int> *takeInput(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BTnode<int> *root = new BTnode<int>(data);
    // BTnode<int> *leftchild = takeInput();
    // BTnode<int> *rightchild = takeInput();
    // root->left = leftchild;
    // root->right = rightchild;
    root->left = takeInput();
    root->right = takeInput();
    return root;
}
void printTree(BTnode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int main(){
    BTnode<int> *root = takeInput();
    printTree(root);
    delete root;
    return 0;
}