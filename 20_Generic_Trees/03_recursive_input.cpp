#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *>children;
    TreeNode(T data){
        this->data = data;
    }
};
template<typename T>
void printTree(TreeNode<T> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}

TreeNode<int>* takeInput(){////although easy but bad way to take input as the user must know recursion
    int data;
    cout<<"Enter data: ";
    cin>>data;
    TreeNode<int> *root=new TreeNode<int>(data);
    int n;
    cout<<"Enter number of nodes for node"<<data<<": ";
    cin>>n;
    for(int i=1;i<=n;i++){
        TreeNode<int> * newnode = takeInput();
        root->children.push_back(newnode);
    }
    return root;
}
int main(){
    TreeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}