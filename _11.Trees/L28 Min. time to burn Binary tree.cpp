https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/



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
class Solution {
public:
    
    TreeNode* parentMapping(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parentOfNode,int start)
    {
        queue<TreeNode*>q;
        q.push(root);
        parentOfNode[root]=NULL;
        TreeNode* res;
        while(!q.empty())
        {
            auto node=q.front();
            if(node->val==start)
                res=node;
            q.pop();
            if(node->left)
            {
                parentOfNode[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                parentOfNode[node->right]=node;
                q.push(node->right);
            }
            
        }
        return res;
    }
    
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode*,TreeNode*>parentOfNode;
        TreeNode* x=parentMapping(root,parentOfNode,start);
        
        int time=0;
        queue<TreeNode*>q;
        q.push(x);
        unordered_map<TreeNode*,int>vis;
        vis[x]=1;
        while(!q.empty())
        {
            int sz=q.size();
            bool f=0;
            
            for(int i=0;i<sz;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left&&!vis[node->left])
                {
                    vis[node->left]=1;
                    q.push(node->left);
                    f=1;
                }
                if(node->right&&!vis[node->right])
                {
                    vis[node->right]=1;
                    q.push(node->right);
                    f=1;
                }
                if(parentOfNode[node]&&!vis[parentOfNode[node]])
                {
                    vis[parentOfNode[node]]=1;
                    q.push(parentOfNode[node]);
                    f=1;
                }
            }
            if(f==1)
                    time++;
        }
        
        return time;
    }
};

---------------------------------------------------------------------------------------------
#include<bits/stdc++.h> 

int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, BinaryTreeNode<int>* target) 
{
    queue<BinaryTreeNode<int>*> q; 
    q.push(target); 
    map<BinaryTreeNode<int>*,int> vis; 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) 
	{
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) 
			{
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) 
			{
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) 
			{
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
                                     map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) 
{
    queue<BinaryTreeNode<int>*> q; 
    q.push(root); 
    BinaryTreeNode<int>* res; 
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); 
        if(node->data == start) res = node; 
        q.pop(); 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp; 
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start);   //stores the address of the node 
	                                                                   //and marks the parent of each node
    int maxi = findMaxDistance(mpp, target); 
    return maxi; 
}
 

