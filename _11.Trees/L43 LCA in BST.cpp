https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/



As soon as the path for both the nodes split, or we come across one of the two nodes
we have found the LCA
============================================================================
ITERATIVE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while(root!=NULL)
        {
            if(p->val<root->val&&q->val<root->val)
            {
                root=root->left;
            }
            else if(p->val>root->val&&q->val>root->val)
            {
                root=root->right;
            }
            else
                return root;
        }
        return root;
    }
};
---------------------------------------------------------------------------------------
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int curr = root->val; 
        if(curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
--------------------------------------------------------------
