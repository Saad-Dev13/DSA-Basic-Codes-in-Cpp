#include <iostream>
using namespace std;
struct BST{
    int data;
    BST* left=NULL;
    BST* right=NULL;
    //BST(){}
    //BST (int data): data(data){}
};
BST* root=NULL;

void Inorder(BST* root){
    if (root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<"";
    Inorder(root->right);
    
}

BST* insert(BST* root, int key){
    if (root==NULL)
    {
        return new BST(key);
    }
    if (key<root->data)
    {
        root->left=insert(root->left,key);

    }
    else
    {
        root->right=insert(root->right,key);
    }
    return root;
    
}

void insertIterative(int key){
    BST* curr=root;
    BST* parent=NULL;
    if (root==NULL)
    {
        root=new BST(key);
        return;
    }
    
}