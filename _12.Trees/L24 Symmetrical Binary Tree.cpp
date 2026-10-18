https://leetcode.com/problems/symmetric-tree/

RECURSIVE:
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        return check(root->left,root->right);
        
    }
    bool check(TreeNode* left, TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if((left!=NULL&&right==NULL)||(left==NULL&&right!=NULL))
        {
            return false;
        }
        if(left->val!=right->val)
            return false;
        
        return check(left->left,right->right)&&check(left->right,right->left);
    }
};

-------------------------------------------------------------------------------
Iterative:

Stack can store NULL

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        stack<TreeNode*>st;
        
        st.push(root->left);
        st.push(root->right);
        while(!st.empty())
        {
            TreeNode* t1=st.top();
            st.pop();
            TreeNode* t2=st.top();
            st.pop();
            if(t1==NULL&&t2==NULL)
                continue;
            if(t1==NULL&&t2!=NULL||t1!=NULL&&t2==NULL)
                return false;
            if(t1->val!=t2->val)
                return false;
            st.push(t1->left);
            st.push(t2->right);
            st.push(t1->right);
            st.push(t2->left);
        }
        
        return true; 
    }
    
};