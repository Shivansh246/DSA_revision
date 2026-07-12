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
/*
properties of Binary search tree:
1-> for every node, all the values in the left subtree are samller than the node
2-> for every node, all the values on the right subtree are larger than the node
*/
BTnode<int> *searchNode(BTnode<int> *root,int x){
    if(root==NULL){
        return NULL;
    }
    /*Recursive =>> space complexity is O(n) because of call stack
    if(root->data==x){
        return root;
    }
    if(root->data > x){
        searchNode(root->left,x);
    }
    return searchNode(root->right,x);
    */
   /*Iterative =>> space complexity is constant*/
   while(root!=NULL){
        if(root->data==x){
            return root;
        }
        if(root->data> x){
            root=root->left;
        }else{
            root=root->right;
        }
   }
   return NULL;
}
int main(){
    BTnode<int> *root = takeInput();
    printTree(root);

    BTnode<int> *node =searchNode(root,3);
    if(node){
        cout<<"Found";
    }else{
        cout<<"Not found";
    }
    delete root;
    return 0;// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
}