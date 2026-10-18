https://leetcode.com/problems/jump-game-iii/ 


Given an array of non-negative integers arr, you are initially positioned 
at start index of the array. When you are at index i, you can 
jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

-------------------------------------------------------------------------------
class Solution 
{
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int n=arr.size();
        vector<int>vis(n,0);
        return dfs(arr,vis,start,n);
    }
    bool dfs(vector<int>& arr,vector<int>&vis,int i,int n)
    {
        if(i>=n)
            return false;
        if(i<0)
            return false;
        if(vis[i])
            return false;
        vis[i]=1;
        if(arr[i]==0)
            return true;
        
        return dfs(arr,vis,i+arr[i],n)||dfs(arr,vis,i-arr[i],n);
            
    }
};
-------------------------------------------------------------------------
BFS
bool canReach(vector<int>& arr, int start) 
{
        int n = arr.size();
        
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        
        vis[start] = true;
        
        while(q.size())
		{
            int i = q.front();
            q.pop();
            
            if(arr[i] == 0)
                return true;
            
            // push i + a[i], i - a[i] and mark visited too.
            if(i + arr[i] < n && !vis[i + arr[i]])
			{
                vis[i+ arr[i]] = true;
                q.push( i + arr[i]);
            }
            
            if(i - arr[i] >= 0 && !vis[i - arr[i]])
			{
                vis[i- arr[i]] = true;
                q.push(i - arr[i]);
            }
        }
        return false;
}