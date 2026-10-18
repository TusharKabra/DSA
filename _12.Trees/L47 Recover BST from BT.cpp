https://leetcode.com/problems/recover-binary-search-tree/

You are given the root of a binary search tree (BST), where the values of 
exactly two nodes of the tree were swapped by mistake. Recover the tree without 
changing its structure.

Observation:
Inorder trav of a BST gives nodes in ascending order.
We can generate the inorder traversal of our BT and it should differ at two places.
There can be two cases:
2 errors:
3 25 7 8 10 15 20 5

1 error:
3 5 8 7 10 15 20 25
===========================================================================
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* last=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        inorder(root->left);
        //Logic
        if(prev!=NULL&&root->val<prev->val)
        {
            //1st error detected
            if(first==NULL)
            {
                first=prev;
                second=root;
                
            }
            //2nd error detected
            else
            {
                last=root;
            }
            
        }
        
        
        prev=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        if(last==NULL)
            swap(first->val,second->val);
        else
            swap(first->val,last->val);
        
        //swap(first,second) or swap(first,last) does not work
    }
};
========================================================
CLEANER CODE:
TreeNode* prev=NULL, *first=NULL,*second=NULL;
void utility (TreeNode* root)
{
   if(root==NULL) return;

   utility(root->left);
   if(prev!=NULL && root->val<prev->val)
   {
       if(first==NULL)
       {
           first=prev;
       }
       second=root;
   }
   prev=root;
   utility(root->right);
}
    void recoverTree(TreeNode* root) {
        
        utility(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }