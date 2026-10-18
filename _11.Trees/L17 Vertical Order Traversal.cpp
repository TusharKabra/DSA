https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
 --------------------------------------------------------------------------------------------
 
class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
	{
        map<int, map<int, multiset<int>>> mp;  //map<x<map <y<multiple nodes>>>
		                                       //using multiset for covering duplicate elements case
		
        queue<pair<TreeNode*, pair<int, int>>> qu; //<node,coordinate pair>
        qu.push({root, {0, 0}});
		
        while (!qu.empty()) 
		{
            auto p = qu.front();
            qu.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node -> val);
            if (node -> left) {
                qu.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                qu.push({node -> right, {x + 1, y + 1}});
            }
        }
		
        vector<vector<int>> ans;
        for (auto p : mp) 
		{
            vector<int> col; //to store each vertical column
            for (auto q : p.second)   //p.second is map<int,multiset<int>> ;q is basically <int,multiset<int>>
			{
			
			//each time inserting at the end of our vector q.second which is basically the multiset. 
			//so each time value associated with one coordinate pushed into col ([-1,1],[-1,2],[-1,3],[-1,3])
                col.insert(col.end(), q.second.begin(), q.second.end()); 
            }
            ans.push_back(col);
        }
        return ans;
    }
};