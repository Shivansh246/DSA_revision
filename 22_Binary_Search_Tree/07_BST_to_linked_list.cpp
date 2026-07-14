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
class Pair{
    public:
    BTnode<int> *head;
    BTnode<int> *tail;
};
class BST{
    BTnode<int> *root;
    void printTree(BTnode<int> *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<": ";
        if(root->left){
            cout<<"L"<<root->left->data<<" ";
        }
        if(root->right){
            cout<<"R"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    bool hasData(BTnode<int> *node, int data){
        if(node==NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }
        if(node->data > data){
            return hasData(node->left, data);
        }else{
            return hasData(node->right, data);
        }
        return false;
    }
    BTnode<int>* insertData(BTnode<int> *node, int data){
        if(node==NULL){
            BTnode<int> *n = new BTnode<int>(data);
            return n;
        }
        if(node->data>data){
            node->left = insertData(node->left,data);
        }
        else{
            node->right= insertData(node->right, data);
        }
        return node;
    }
    int maxBST(BTnode<int> *root){
        if(root==NULL){
            return -1;
        }
        while(root->right!=NULL){
            root=root->right;
        }
        return root->data;
    }
    BTnode<int>* deleteData(BTnode<int> *node, int data){
        if(node==NULL){
            return NULL;
        }
        if(node->data > data){
            node->left = deleteData(node->left,data);
        }else if(node->data < data){
            node->right= deleteData(node->right,data);
        }else{/// the node to be deleted is found
            if(node->left==NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->right==NULL){
                BTnode<int>*temp = node->left;
                node->left=NULL;//isolation step , very important
                delete node;/// if not isolated it will delete whole tree ahead of it, as the destructor is recursive
                return temp;
            }
            else if(node->left==NULL){
                BTnode<int>*temp = node->right;
                node ->right= NULL;
                delete node;
                return temp;
            }
            else{///we can replace with min of right or maximum of left, here minimum of right
                BTnode<int>* minNode = node->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
                int rightMin = minNode->data;
                node->data =rightMin ;
                node->right =deleteData(node->right,rightMin);
            }
        }
        return node;
    }
    Pair convertToLL(BTnode<int> *node){
        if(node==NULL){
            Pair ans;
            ans.head==NULL;
            ans.tail==NULL;
            return ans;
        }
        if(node->left==NULL && node->right==NULL){
            Pair p;
            p.head=node;
            p.tail=node;
            return p;
        }else if(node->left!=NULL && node->right==NULL){
            Pair leftLL = convertToLL(node->left);
            leftLL.tail->right = node;
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = node;
            return ans;
        }else if(node->left==NULL && node->right!=NULL){
            Pair rightLL = convertToLL(node->right);
            node->right = rightLL.head;
            Pair ans;
            ans.head=node;
            ans.tail = rightLL.tail;
            return ans;
        }else{
            Pair leftLL=convertToLL(node->left);
            Pair rightLL = convertToLL(node->right);
            
            leftLL.tail->right = node;
            node->right = rightLL.head;

            Pair ans;
            ans.head = leftLL.head;
            ans.tail = rightLL.tail;
            return ans;
        }
    }
    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    void print(){
        printTree(root);
    }
    void insertData(int data){
        root = insertData(root,data);
    }
    void deleteData(int data){
        root=deleteData(root,data);
    }
    bool hasData(int data){
        return hasData(root,data);/// private function required as for recursion the required function signature is not present with this function
    }
    BTnode<int> *convertToLL(){
        Pair p = convertToLL(root);
        BTnode<int> *temp = p.head;
        while(temp!=NULL){
            temp->left=NULL;
            temp=temp->right;
        }
        return p.head;
    }
};
int main(){
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);
    b.print();
    cout<<endl;
    BTnode<int> *LL = b.convertToLL();
    BTnode<int> *temp=LL;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->right;
    }
    return 0;
}