#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    vector<int> v;
    solve(root, v);
    if(k>v.size()) return -1;
    return v[k-1];
}