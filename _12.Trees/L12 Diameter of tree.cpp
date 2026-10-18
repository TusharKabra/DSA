 https://leetcode.com/problems/diameter-of-binary-tree/

Diameter of Binary tree
//Variation of Max Depth of tree

Longest path between any two nodes in the tree. The path does not need to pass through the root.

class Solution 
{
public:
    int diameterOfBinaryTree(TreeNode* root) 
	{
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) 
	{
        if (node==NULL) 
		{
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};
