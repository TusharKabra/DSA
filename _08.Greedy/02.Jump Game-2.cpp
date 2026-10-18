https://leetcode.com/problems/jump-game-ii/

IDEA=1D BFS

At each step, we need to see what is the max point we can reach from that index.
Divide the array into different levels based on that.

nodes in level i are all the nodes that can be reached in i-1th jump. for example. 2 3 1 1 4 , is
2||
3 1||
1 4 ||

============================================================
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        
        int mx_reach=0;
        int level=0;
        int l=0;int r=0;
        int farthest=0;
        while(r<n-1)
        {
            
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,nums[i]+i);
                if(farthest>=n-1)
                    return level+1;
            }
            l=r+1;
            r=farthest;
            level++;
        }
       return level;
    }
};

=====================
TC=O(n)