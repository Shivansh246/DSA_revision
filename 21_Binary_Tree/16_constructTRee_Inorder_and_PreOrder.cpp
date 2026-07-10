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

BTnode<int> *buildTreehelper(vector<int> inorder,vector<int> preorder,int inS,int inE,int preS,int preE){
    if(inS>inE){
        return NULL;
    }
    int rootData=preorder[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int leftInS=inS;
    int leftInE=rootIndex-1;
    int leftPreS=preS+1;///leftInE - leftInS = leftPreE - leftPreS =>>
    int leftPreE=leftInE +leftPreS - leftInS;

    int rightInS=rootIndex+1;
    int rightInE=inE;
    int rightPreS=leftPreE+1;
    int rightPreE=preE;

    BTnode<int> *root = new BTnode<int>(rootData);
    root->left = buildTreehelper(inorder,preorder,leftInS,leftInE,leftPreS,leftPreE);
    root->right = buildTreehelper(inorder,preorder,rightInS,rightInE,rightPreS,rightPreE);
    return root;
}
BTnode<int> *buildTree(vector<int> inorder,vector<int> preorder){
    int n = inorder.size();
    return buildTreehelper(inorder,preorder,0,n-1,0,n-1);
}
int main(){
    vector<int> Preorder = {1,2,4,5,6,7,3,8,9};
   vector<int> Inorder = {4,2,6,5,7,1,8,3,9};
   BTnode<int> *root = buildTree(Inorder,Preorder);
    printTree(root);
    delete root;
    return 0;
}