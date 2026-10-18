
//Algo
1.move to the left most node. keep storing the nodes in the stack
2.When the current node points to NULL, it means that there is 
nothing left to traverse and we should move to the parent. This 
parent is always placed at the top of the stack. If the stack is empty, 
then we had already traversed the whole tree and should stop the execution.



class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
	{
        stack<TreeNode*> st; 
        TreeNode* node = root;
        vector<int> inorder; 
        while(true) 
		{
            if(node != NULL) 
			{
                st.push(node); 
                node = node->left; 
            }
            else 
			{
			
    
                if(st.empty() == true)  //No nodes left to travel
				break; 
				
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->val); 
                node = node->right; 
            }  
        }
        return inorder; 
    }
};
