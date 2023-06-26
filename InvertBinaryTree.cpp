void solve(TreeNode* root)
    {
        if(root==NULL) return;
        swap(root->left, root->right);
        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;

    }