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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> v;
    vector<vector<int>> t;
    if(root==NULL) return v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool lr=true;
    while(!q.empty())
    {
        int n=q.size();
        vector<int> temp;
        for(int i=0; i<n; i++)
        {
            BinaryTreeNode<int> * curr=q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(!lr)
        {
            reverse(temp.begin(), temp.end());

        }
        t.push_back(temp);
        lr=!lr;
    }
    for(int i=0; i<t.size(); i++)
    {
        for(int j=0; j<t[i].size(); j++)
        {
            v.push_back(t[i][j]);
        }
    }
    return v;
}
