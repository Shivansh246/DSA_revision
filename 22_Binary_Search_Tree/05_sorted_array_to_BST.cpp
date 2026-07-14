#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BTnode{
    public:
    T data;
    BTnode<T> *left;
    BTnode<T> *right;
    BTnode(T data){
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
BTnode<int> *helper(vector<int> &v,int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    BTnode<int> *root = new BTnode<int>(v[mid]);
    root->left = helper(v,s,mid-1);
    root->right = helper(v,mid+1,e);
    return root;
}
BTnode<int> *sortedArraytoBST(vector<int> &v){
    int n = v.size();
    return helper(v,0,n-1);
}
int main(){
    vector<int> v={-10,-3,0,5,9};
    BTnode<int> *root = sortedArraytoBST(v);
    printTree(root);
    
    delete root;
    return 0;
}