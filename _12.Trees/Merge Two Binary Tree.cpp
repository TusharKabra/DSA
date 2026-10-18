https://leetcode.com/problems/merge-two-binary-trees/

The merge rule is that if two nodes overlap, then sum node values 
up as the new value of the merged node. Otherwise, the NOT null 
node will be used as the node of the new tree.

Return the merged tree.
----------------------------------------------------------------
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL&&root2==NULL)
            return NULL;
        if(root1==NULL)
            return root2;
        if(root2==NULL)
            return root1;
        
        
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        
        return root1;
    }
};