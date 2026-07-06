/*
for deleting the tree, first delete the child then delete the node or the location of children will be lost and cannot be deleted*/
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
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
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

int main(){
    TreeNode<int> *root = takeInput();
    printTree(root);
    delete root;/*
    delete function works such that it first calls the destrutor of the object then deletes the object
    on case of default destructor there is no code in the destructor hence the object just deletes
    in this destrucor it first deletes the children as instructed by the destructor
    */
    printTree(root);
    return 0;
}
