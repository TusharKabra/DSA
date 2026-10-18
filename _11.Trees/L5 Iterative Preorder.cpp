ALGO
//
1.Get topmost element of stack
2.store this value and pop
3.Push the stored value in vector
4.check for right and then left and push both in the stack 
as when popping out the elements come out in reverse
5.Repeat till stack is empty
-------------------------------------------------------------------

class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) 
	{
        vector<int> preorder;
		
        if(root == NULL) 
		return preorder;   //empty tree
       
        stack<TreeNode*> st; 
        st.push(root);
        while(!st.empty())
		{
            root = st.top();
            st.pop(); 
            preorder.push_back(root->val); 
			
//we first push right and then push left as we will be using the topmost 
//element of stack and while popping, left will pop out first
			
            if(root->right != NULL)
			{             
                st.push(root->right);
            }
            if(root->left!= NULL)
			{
                st.push(root->left);
            }
        }
        return preorder; 
    }
};

//T.C=O(n)
//S.C=O(n) 