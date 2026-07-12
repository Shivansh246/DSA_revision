#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BTnode{
    public:
    T data;
    BTnode<T> *left;
    BTnode<T> *right;
    BTnode(int data){
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
bool helper(BTnode<int> *root,int minV = INT_MIN, int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    bool left = helper(root->left,minV,root->data);
    bool right = helper(root->right, root->data,maxV);
    if(left &&right && root->data < maxV && root->data > minV){
        return true;
    }
    return false;
}
bool checkBST(BTnode<int> *root){
    return helper(root);
}
/*checkBST by checking if inorder traversal is sorted
we may not create an array and use to pointers to check if the traversal is sorted and making space complexity O(1)*/
int main(){
    BTnode<int> *root = takeInput();
    printTree(root);
    if(checkBST(root)){
        cout<<"BST";
    }else{
        cout<<"NOT bst";
    }
    delete root;
    return 0;// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
}