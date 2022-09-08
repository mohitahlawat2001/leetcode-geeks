/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root)
{
    if(!root) return { };
	if(!root->left and !root->right) return {root->val};

	vector<int> result;
	stack<TreeNode*> s;

    while(!s.empty() or root != NULL)
	{
		if(root != NULL)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			root = s.top();
			s.pop();
			result.push_back(root->val);
			root = root->right;
		}
	}
	return result;
    
}};