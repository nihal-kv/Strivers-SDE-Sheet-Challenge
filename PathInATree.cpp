#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool solve(TreeNode<int> * root, vector<int>& v, int x)
{
	if(root==NULL) return false;
	v.push_back(root->data);
	if(root->data==x) 
	{
		return true;
	}
	if(solve(root->left, v, x) || solve(root->right, v, x)) return true;

	v.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> v;
	solve(root, v, x);
	return v;
}
