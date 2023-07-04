#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long solve(TreeNode<int> * root, long long& maxi)
{
    if(root==NULL) return 0;

    int left=solve(root->left, maxi);
    int right=solve(root->right, maxi);

    if(root->val+left+right>maxi) maxi=root->val+left+right;
    return root->val+max(left, right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long maxi=0;
    if(root==NULL) return -1;
    if(root->left==NULL || root->right==NULL) return -1;
    solve(root, maxi);
    return maxi;
}