#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> v;
    if(root==NULL) return v;
    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        
        TreeNode<int> * curr=it.first;
        int x=it.second;
        
        mp[x].push_back(curr->data);

        if(curr->left)
          q.push({curr->left, x - 1});
        if(curr->right)
        {
            q.push({curr->right, x+1});
        }
    }
 
    for(auto it: mp)
    {
        for(auto x: it.second)
        {
            v.push_back(x);
        }
    }
    return v;
}