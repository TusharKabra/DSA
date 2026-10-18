

https://leetcode.com/problems/path-sum-iii/

Given the root of a binary tree and an integer targetSum, return the 
number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must 
go downwards (i.e., traveling only from parent nodes to child nodes).
-------------------------------------------------------------------------

class Solution {
public:
    int pathSum(TreeNode* root, int sum) 
	{
        unordered_map<long long int, long long int> m;
        m[0]++;
        
        long long int total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    
    void helper(TreeNode *p, long long int cur, long long int sum, long long int &total, unordered_map<long long int, long long int> &m) 
	{
        if (!p) return;
        
        cur += p->val;
		
        if (m.find(cur - sum) != m.end()) 
		   total += m[cur - sum];
		   
        m[cur]++;
        
        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);
        
        m[cur]--;
    }
};