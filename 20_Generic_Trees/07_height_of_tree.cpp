#include <bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data = data;
    }
};
TreeNode<int> *takeInput(){
    int rootdata;
    cout<<"Enter root data: ";
    cin>>rootdata;
    TreeNode<int>*root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int> *f=q.front();
        q.pop();
        int n;
        cout<<"Enter no of nodes for node "<<f->data<<": ";
        cin>>n;
        for(int i=1;i<=n;i++){
            int childData;
            cout<<"Enter data for "<<i<<"th"<<" node of "<<f->data<<": ";
            cin>>childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            q.push(childNode);
            f->children.push_back(childNode);
        }
    }
    return root;
}
void printTree(TreeNode<int> *root){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *f = q.front();
        q.pop();
        cout<<f->data<<": ";
        for(int i=0;i<f->children.size();i++){
            q.push(f->children[i]);
            cout<<f->children[i]->data<<", ";
        }
        cout<<endl;
    }
}
int height(TreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int mx=0;
    for(int i=0;i<root->children.size();i++){
        int c_height = height(root->children[i]);
        if(c_height>mx){
            mx=c_height;
        }
    }
    return mx+1;
}
int main(){
    TreeNode<int> *root = takeInput();
    printTree(root);
    cout<<"Height = "<<height(root);
    return 0;
}