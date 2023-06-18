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
int height(TreeNode<int> * root)
{
    if(root==NULL) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l, r);
}
void solve(TreeNode<int> * root, int& maxi)
{
    if(root==NULL) return;
    int l=height(root->left);
    int r=height(root->right);
    int d=l+r;
    maxi=max(maxi, d);
    solve(root->left, maxi);
    solve(root->right, maxi);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int maxi=0;
    solve(root, maxi);
    return maxi;
}
