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
void postOrderTraversal(BTnode<int>*root){/// LeftTree ->> RightTree ->> data ///bottom up approach
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    BTnode<int> *root =takeInput();
    postOrderTraversal(root);
    delete root;
    return 0;
}