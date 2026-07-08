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
void levelOrderPrint(BTnode<int> *root){
    if(root==NULL){
        return;
    }
    queue<BTnode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BTnode<int>*f = q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(f);
            }else{
                return;
            }
        }else{
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}
void levelOrderPrint2(BTnode<int> *root){
    queue<BTnode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        for(int i=0;i<level;i++){
            BTnode<int> *f = q.front();
            q.pop();
            cout<<f->data<<" ";
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        cout<<endl;
    }
}
void InOrderTraversal(BTnode<int> *root){/// first print left node then root then right node
    if(root==NULL){
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}
int main(){
    BTnode<int> *root =takeInput();
    levelOrderPrint(root);
    cout<<endl;
    InOrderTraversal(root);
    delete root;
    return 0;
}