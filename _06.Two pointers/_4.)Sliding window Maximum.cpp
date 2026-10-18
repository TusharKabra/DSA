https://leetcode.com/problems/sliding-window-maximum/

---------------------------------------------------------------
O(NlogN)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        priority_queue<pair<int,int>>pq; //{number,index}
        int i=0;
        int j=0;
        int n=nums.size();
        vector<int>ans;
        while(j<n)
        {
            pq.push({nums[j],j});
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                while(!pq.empty()&&pq.top().second<i)
                {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;
                j++;
                
            }
            
            
        }
        return ans;
        
    }
};

-------------------------------------------------------------
DEQUEUE SOLUTION (O(N))
