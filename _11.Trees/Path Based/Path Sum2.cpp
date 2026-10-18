https://leetcode.com/problems/path-sum-ii/

Given the root of a binary tree and an integer targetSum, return 
all root-to-leaf paths where the sum of the node values in the path 
equals targetSum. Each path should be returned as a list of the node 
values, not node references.
------------------------------------------------------------------------
Bottom-UP:

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>ans;
        vector<int>v;
        int sum=0;
        solve(root,targetSum,v,ans,sum);
        return ans;
        
    }
    void solve(TreeNode* root, int t,vector<int>&v,vector<vector<int>>&ans,int sum)
    {
        if(root==NULL)
            return;
        
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum+root->val==t)
        {
            ans.push_back(v);
            
        }
        solve(root->left,t,v,ans,sum+root->val);
        solve(root->right,t,v,ans,sum+root->val);
        v.pop_back();
    }
};
--------------------------------------------------------------------------
TOP-DOWN:

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};