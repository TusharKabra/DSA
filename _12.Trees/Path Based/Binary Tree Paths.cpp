
https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    
    void generate(TreeNode* root,string x, vector<string>&ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            x+=to_string(root->val);
            ans.push_back(x);
            return;
        }
        x+=to_string(root->val);
        x+="->";
        generate(root->left,x,ans);
        generate(root->right,x,ans);
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        
        string x="";
        vector<string>ans;
        
        generate(root,x,ans);
        
        return ans;
        
    }
};