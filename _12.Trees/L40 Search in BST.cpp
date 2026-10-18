https://leetcode.com/problems/search-in-a-binary-search-tree/


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        while(root!=NULL)
        {
            if(root->val<val)
            {
                root=root->right;
            }
            else if(root->val>val)
            {
                root=root->left;
            }
            else
                return root;
        }
        return root;
        
    }
};