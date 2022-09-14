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
    void helper(TreeNode* root,int& ans,int map[]){
        if(!root) return;
    
        map[root->val]++; 
        helper(root->left,ans,map); 
        helper(root->right,ans,map); 
          
        if(!root->left && !root->right){ 
             int odd_cnt=0;
             for(int i=1;i<=9;i++){  
                if(map[i]!=0 && (map[i]%2)!=0) ++odd_cnt;  
              }
             if(odd_cnt<=1) ++ans;  
        }                
        map[root->val]--;   
    }
    
    int pseudoPalindromicPaths (TreeNode* root){
        int ans=0;
        int map[10]={0};
        helper(root,ans,map);
        return ans;    
    }
};