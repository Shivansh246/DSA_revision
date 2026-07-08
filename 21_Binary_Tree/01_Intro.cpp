#include <bits/stdc++.h>
using namespace std;
/*
Binary Tree-> a node can have a maximum of two childs
*/
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
    ~BTnode(){
        delete left;
        delete right;
    }
};
int main(){
    BTnode<int> *root = new BTnode<int>(1);
    BTnode<int> *n1 = new BTnode<int>(1);
    BTnode<int> *n2 = new BTnode<int>(1);
    root->left = n1;
    root->right = n2;
    delete root;
    return 0;
}