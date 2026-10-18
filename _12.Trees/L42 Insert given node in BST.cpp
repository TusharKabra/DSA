https://leetcode.com/problems/insert-into-a-binary-search-tree/


Observation:
1.)We can always insert the given node at any of the suitable leaf.
2.)Also tricky edge case of root being NULL, then we need to return 
only the newly formed node as the answer
=============================================================================

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        
        TreeNode* temp=root;
        TreeNode* x=new TreeNode(val);
        x->left=NULL;
        x->right=NULL;
        if(root==NULL)
            return x;
        while(root!=NULL)
        {
             if(root->val<val)
             {
                 if(root->right)
                     root=root->right;
                 else break;
             }
            else if(root->val>val)
            {
                if(root->left)
                    root=root->left;
                else break;
            }
        }
        if(root->val<val)
            root->right=x;
        else
            root->left=x;
        
        return temp;
        
        
    }
};