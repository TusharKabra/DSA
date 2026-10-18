https://leetcode.com/problems/path-sum/

Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.

A leaf is a node with no children.
-----------------------------------------------------------------------
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int sum=0;
        return solve(root,targetSum,sum);
        
    }
    bool solve(TreeNode* root,int t,int sum)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL&&root->right==NULL)
        {
            if(sum+root->val==t)
                return true;
            else
                return false;
        }
        
        return solve(root->left,t,sum+root->val)||solve(root->right,t,sum+root->val);
        
        
    }
};