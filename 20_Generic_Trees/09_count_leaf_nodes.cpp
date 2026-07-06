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
int countLeafNodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;//// not a base case
    }
    if(root->children.size()==0){
        return 1;//// base case
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=countLeafNodes(root->children[i]);
    }
    return ans;
}
void countLeafNodesOtherWay(TreeNode<int> *root,int &ans){
    if(root == NULL){
        ans=0;
        return;//// not a base case
    }
    if(root->children.size()==0){
        ans++;//// base case
        return;
    }
    for(int i=0;i<root->children.size();i++){
        countLeafNodesOtherWay(root->children[i],ans);
    }
}
int main(){
    TreeNode<int> *root = takeInput();
    printTree(root);
    cout<<endl;
    cout<<"Number of leaf nodes = "<<countLeafNodes(root);
    int ans=0;
    countLeafNodesOtherWay(root,ans);
    cout<<endl;
    cout<<"Other way for leaf nodes: "<<ans;
    return 0;
}// 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0 