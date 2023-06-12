#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> v;
    if(root==NULL) return v;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        BinaryTreeNode<int> * curr=it.first;
        int level=it.second;
        mp[level]=curr->data;
        if(curr->left) q.push({curr->left, level-1});
        if(curr->right) q.push({curr->right, level+1});
    }
    for(auto it: mp)
    {
        v.push_back(it.second);
    }
    return v;
    
}
