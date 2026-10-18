BALANCED TREE IS ONE IN WHICH THE DIFFERENCE BETWEEN THE HEIGHT OF left and right SUBTREE OF ANY NODE IS AT MOST ONE

https://leetcode.com/problems/balanced-binary-tree/ 

NAIVE SOLUTION

For the current node root, calling depth() for its left and right children actually has 
to access all of its children, thus the complexity is O(N). We do this for each node in 
the tree, so the overall complexity of isBalanced will be O(N^2). This is a top down approach.

class solution {
public:
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);
        int right=depth(root->right);
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

---------------------------------------------------------------------------------
Optimised O(N) Solution:

When the sub tree of the current node (inclusive) is balanced, 
the function dfsHeight() returns a non-negative value as the height. 
Otherwise -1 is returned. 
According to the leftHeight and rightHeight of the two children, the parent node could check if the sub tree
is balanced, and decides its return value.

class Solution {
public:
    bool isBalanced(TreeNode* root) 
	{
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode *root) 
	{
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) 
			return -1;
		
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) 
			return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
			return -1;
		
        return max (leftHeight, rightHeight) + 1;
    }
};



