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

BTnode<int> *buildTreehelper(vector<int> inorder,vector<int> postorder,int inS,int inE,int postS,int postE){
    if(inS>inE){
        return NULL;
    }
    int rootData=postorder[postE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int leftInS=inS;
    int leftInE=rootIndex-1;
    int leftPostS=postS;
    int leftPostE=leftInE +leftPostS - leftInS;///leftInE - leftInS = leftPostE - leftPostS =>>

    int rightInS=rootIndex+1;
    int rightInE=inE;
    int rightPostS=leftPostE+1;
    int rightPostE=postE-1;

    BTnode<int> *root = new BTnode<int>(rootData);
    root->left = buildTreehelper(inorder,postorder,leftInS,leftInE,leftPostS,leftPostE);
    root->right = buildTreehelper(inorder,postorder,rightInS,rightInE,rightPostS,rightPostE);
    return root;
}
BTnode<int> *buildTree(vector<int> inorder,vector<int> postorder){
    int n = inorder.size();
    return buildTreehelper(inorder,postorder,0,n-1,0,n-1);
}
int main(){
    vector<int> Postorder = {9,15,7,20,3};
   vector<int> Inorder = {9,3,15,20,7};
   BTnode<int> *root = buildTree(Inorder,Postorder);
    printTree(root);
    delete root;
    return 0;
}