#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int>* root, vector<int>& v)
{
    if(root==NULL) return;
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<int> v;
    solve(root, v);
    int i=0;
    BinaryTreeNode<int>* dummy=new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* temp=dummy;
    while(i<v.size())
    {
        BinaryTreeNode<int>* t=new BinaryTreeNode<int>(v[i]);
        i++;
        temp->right=t;
        t->left=temp;
        temp=t;
    }
    return dummy->right;
}