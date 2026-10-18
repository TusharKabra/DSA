https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

A path in the binary tree is said to be pseudo-palindromic if at 
least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
-------------------------------------------------------------------------------------

class Solution {
public:

    //pallin function checks if sequence can from pallindrome by 
	//checking wheteher we have only one or less elemnts with odd freq.
	
	
     bool pallin(vector<int>&freq) 
    {
        
        int c=0;
        for(int i=1;i<=9;i++)
        {
            if(freq[i]%2==1)
                c++;
        }
        return c<=1;
    }
    int pseudoPalindromicPaths(TreeNode* root) 
    {
        vector<int>freq(10,0);
        int c=0;
        solve(root,freq,c);
        return c;
        
    }
    void solve(TreeNode* root,vector<int>&freq,int &c)
    {
        if(root==NULL)
            return;
        
        freq[root->val]++;
        
        if(root->left==NULL&&root->right==NULL)
        {
            c+=pallin(freq);
        }
        
        solve(root->left,freq,c);
        solve(root->right,freq,c);
        
        freq[root->val]--;
    }
};
-------------------------------------------------------------

The problem could be solved in constant space using the Morris inorder traversal 
algorithm, as it was done in Sum Root-to-Leaf Numbers. It is unlike that one can 
come up a Morris solution during an interview, but it is worth to know anyway.