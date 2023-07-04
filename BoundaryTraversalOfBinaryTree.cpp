#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root)
{
    return root->left==NULL && root->right==NULL;
}

void addLeft(TreeNode<int>* root, vector<int>& v)
{
    TreeNode<int>* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr)) v.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addRight(TreeNode<int>* root, vector<int>& v)
{
    TreeNode<int>* curr=root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1; i>=0; i--)
    {
        v.push_back(temp[i]);
    }
}

void addLeaves(TreeNode<int>* root, vector<int>& v)
{
    if(isLeaf(root))
    {
        v.push_back(root->data);
        return;
    } 

    if(root->left) addLeaves(root->left, v);
    if(root->right) addLeaves(root->right, v);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> v;
    if(root==NULL) return v;
    if(!isLeaf(root)) v.push_back(root->data);
    addLeft(root, v);
    addLeaves(root, v);
    addRight(root, v);
    return v;
}