https://leetcode.com/problems/binary-tree-level-order-traversal/ 


Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
-------------------------------------------------------------------------------------------------- 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        vector<vector<int>>ans;
        vector<int>temp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto x=q.front();
                q.pop();
                if(x->left!=NULL)
                {
                    q.push(x->left);   
                }  
                if(x->right!=NULL)
                {
                    q.push(x->right);
                }
                temp.push_back(x->val);
            }
            ans.push_back(temp);
            temp.clear();   //very important   
        }
        return ans;
        
    }
};