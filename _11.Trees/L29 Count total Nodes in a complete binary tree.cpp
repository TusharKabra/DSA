 https://leetcode.com/problems/count-complete-tree-nodes/

A complete binary tree is a binary tree in which every level, 
except possibly the last, is completely filled, and all nodes 
in the last level are as far left as possible.
---------------------------------------------------------------------------
Logic: We compute the height of left node and right node. If height same then 
that subtree is complete and we have a formula


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; //No. of nodes when subtree is complete
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    int findHeightLeft(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
};

T.C.=O((logN)^2)
Height of the tree is log(N)
We are doing at max logN traversals

S.C.=O(logN)