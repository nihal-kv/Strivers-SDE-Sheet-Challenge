#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> v;
    if(root==NULL) return v;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        TreeNode<int> * curr=it.first;
        int level=it.second;
        if(mp.find(level)==mp.end()) mp[level]=curr->val;
        if(curr->left) q.push({curr->left, level-1});
        if(curr->right) q.push({curr->right, level+1});
    }
    for(auto it: mp)
    {
        v.push_back(it.second);
    }
    return v;
}