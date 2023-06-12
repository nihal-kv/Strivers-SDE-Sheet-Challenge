#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int ans;
    while(root)
    {
        if(root->val==x) return root->val;
        else if(root->val>x)
        {
            root=root->left;
        } 
        else 
        {
            ans = root->val;
            root=root->right;
        }
    }
    return ans;
}