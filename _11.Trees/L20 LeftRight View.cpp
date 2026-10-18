https://leetcode.com/problems/binary-tree-right-side-view/

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)
            return ans;
        rightview(ans,root,0);
        return ans;
        
        
        
    }
    void rightview(vector<int>&ans,TreeNode* root,int level)
    {
        if(root==NULL)
            return;
        if(ans.size()==level)
            ans.push_back(root->val);
        
        rightview(ans,root->right,level+1);
        rightview(ans,root->left,level+1);
    }
    
};
-----------------------------------------------------------------------------------
//for leftview just need to write root->left recursion first and then root->right;
---------------------------------------------------------------------------------

BFS APPROACH: just add the last node in each level to the result.

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
	{
        if (!root) 
		{
            return {};
        }
        vector<int> view;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == n - 1) {
                    view.push_back(node -> val);
                }
                if (node -> left) {
                    todo.push(node -> left);
                }
                if (node -> right) {
                    todo.push(node -> right);
                }
            }
        }
        return view;
    }
};