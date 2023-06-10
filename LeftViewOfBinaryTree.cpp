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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> v;
    if(root==NULL) return v;
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0; i<n; i++)
        {
            TreeNode<int> * curr=q.front();
            q.pop();
            if(i==0) v.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return v;
}