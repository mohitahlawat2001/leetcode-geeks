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
    void dfs(TreeNode* root , int &n){
        if(root==NULL) return;
        if(root->left) dfs(root->left,++n);
        if(root->right) dfs(root->right,++n);
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int n=1;
        dfs(root,n);
        return n;
    }
};