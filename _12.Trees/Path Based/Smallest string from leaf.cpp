https://leetcode.com/problems/smallest-string-starting-from-leaf/

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        string ans="~";  //clever way to initialise string as infinity
        string s="";
        solve(root,ans,s);
        return ans;
        
    }
    void solve(TreeNode* root, string &ans,string s)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL&&root->right==NULL)
        {
            s+=char(root->val+'a');
            // cout<<s<<endl;
            reverse(s.begin(),s.end());
            ans=min(ans,s);
        }
        
        solve(root->left,ans,s+char(root->val+'a'));
        solve(root->right,ans,s+char(root->val+'a'));
		
		//we dont have s.pop() here as we did a pass by value rather than reference
        
    }
};

--------------------------------------------------------------
More Optimal(No reverse needed)

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        string ans="~";
        string s="";
        solve(root,ans,s);
        return ans;
        
    }
    void solve(TreeNode* root, string &ans,string s)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL&&root->right==NULL)
        {
            
            // cout<<s<<endl;
            // reverse(s.begin(),s.end());
            ans=min(ans,char(root->val+'a')+s);
        }
        
        solve(root->left,ans,char(root->val+'a')+s); //append char at beginning to generate reverse.
        solve(root->right,ans,char(root->val+'a')+s);
        
    }
};