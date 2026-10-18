https://leetcode.com/problems/validate-binary-search-tree/


ALGO:For each node check whether it is in the correct range.
--------------------------------------------------------------
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return solve(root,-1e17,1e17);
        
    }
    bool solve(TreeNode* root,long long int min,long long int max)
    {
        if(root==NULL)
            return true;
        
        if(root->val>=max||root->val<=min)
        {
            return false;
        }
        return solve(root->left,min,root->val)&&solve(root->right,root->val,max);
    }
};