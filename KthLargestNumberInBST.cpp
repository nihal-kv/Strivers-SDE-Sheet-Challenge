#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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
void solve(TreeNode<int>* root, vector<int>& v)
{
    if(root==NULL) return;
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> v;
    solve(root, v);
    if(k>v.size()) return -1;
    reverse(v.begin(), v.end());
    return v[k-1];
}
