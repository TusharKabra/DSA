Concept: https://www.youtube.com/watch?v=66w10xKzbRM 
GFG:
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

1. If A[i] is smallest among all end 
   candidates of active lists, we will start 
   new active list of length 1.
2. If A[i] is largest among all end candidates of 
  active lists, we will clone the largest active 
  list, and extend it by A[i].
3. If A[i] is in between, we will find a list with 
  largest end element that is smaller than A[i]. 
  Clone and extend this list by A[i]. We will discard all
  other lists of same length as that of this modified list.


//Leetcode implementn

//Must see for explan:
https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>temp;
        
        if(nums.size()==0)
            return 0;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp[temp.size()-1])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
                *it=nums[i];
            }
        }
        return temp.size();
        
    }
};
