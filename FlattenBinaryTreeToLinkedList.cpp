#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root, vector<int>& v)
{
    if(root==NULL) return;
    v.push_back(root->data);
    solve(root->left, v);
    solve(root->right, v);
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return NULL;
    vector<int> v;
    solve(root, v);
    TreeNode<int> * dummy=new TreeNode<int>(-1);
    TreeNode<int> * temp=dummy;
    for(int i=0; i<v.size(); i++)
    {
        TreeNode<int> * t=new TreeNode<int>(v[i]);
        temp->right=t;
        temp=t;
    }
    return dummy->right;
}