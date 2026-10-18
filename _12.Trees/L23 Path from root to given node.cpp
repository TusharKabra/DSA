https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/

https://www.interviewbit.com/problems/path-to-given-node/

-------------------------------------------------------------------------

// Returns true if there is a path from root
// to the given node. It also populates
// 'arr' with the given path

bool hasPath(Node *root, vector<int>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->data);   
     
    // if it is the required node
    // return true
    if (root->data == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
	
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
	
    arr.pop_back();
    return false;           
}
 
// function to print the path from root to the
// given node if the node lies in the binary tree
void printPath(Node *root, int x)
{
    // vector to store the path
    vector<int> arr;
     
    // if required node 'x' is present
    // then print the path
    if (hasPath(root, arr, x))
    {
        for (int i=0; i<arr.size()-1; i++)   
            cout << arr[i] << "->";
        cout << arr[arr.size() - 1];   
    }
     
    // 'x' is not present in the binary tree
    else
        cout << "No Path";
}


Time complexity: O(n) in worst case, where n is the number of nodes in the binary tree.
 


