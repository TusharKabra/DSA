https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int val) 
{
    int ans=-1; //-1 because if val is greater than all elem of tree then ceil does not exist.
    while(root!=NULL)
    {
        if(root->data<val)
        {
            root=root->right;
        }
        else if(root->data>val)
        {
            ans=root->data;
            root=root->left;
        }
        else if(root->data==val)
        {
            return root->data;
        }
        
    }
    return ans;

    // Your code here
}