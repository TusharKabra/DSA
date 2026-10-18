https://leetcode.com/problems/sum-root-to-leaf-numbers/

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers.

------------------------------------------------------------
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
-------------------------------------------------------------


class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        int sum=0;
        int ans=0;
        solve(root,sum,ans);
        return ans;
        
    }
    void solve(TreeNode* root,int sum,int &ans)
    {
        if(root==NULL)
            return;
        
        sum=sum*10+root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            ans+=sum;
        }
        
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);

    }
};