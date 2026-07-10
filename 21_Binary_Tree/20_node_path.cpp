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
bool getPath(BTnode<int> *root,int x,vector<int> &v){
    if(root==NULL){
        return false;
    }
    v.push_back(root->data);
    if(root->data==x){
        return true;
    }
    if(getPath(root->left,x,v) || getPath(root->right,x,v)){
        return true;
    }
    v.pop_back();
    return false;

}

int main(){
    BTnode<int> *root =takeInput();
    printTree(root);
    vector<int> v;
    if(getPath(root,4,v)){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }else{
        cout<<"Value not found";
    }
    delete root;
    return 0;
}