#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int>* root, vector<int>& v)
{
    if(root==NULL) return;
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    vector<int> v;
    pair<int, int> p;
    solve(root, v);
    if(v.size()==1)
    {
        p.first=-1;
        p.second=-1;
        return p;
    }
    if(v[0]==key)
    {
        p.first=-1;
        p.second=v[1];
    }
    else if(v[v.size()-1]==key) 
    {
        p.first=v[v.size()-2];
        p.second=-1;
    }
    else
    {
        for(int i=1; i<v.size()-1; i++)
        {
            if (v[i] == key) 
            {
                p.first = v[i - 1];
                p.second = v[i + 1];
            }
        }
    }
    return p;
}
