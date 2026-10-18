https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers nums and an integer k, 
return the total number of subarrays whose sum equals to k.

1 <= nums.length <= 2 * 1e4
-1000 <= nums[i] <= 1000
-1e7 <= k <= 1e7

class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) 
    {
        //Basic logic is prefixsum[i]-prefixsum[j]==k for i>=j;
		
        int n=nums.size();
        map<int,int>mp;
        int sum=0;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
           
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];//consider case k=9 and [0 0 0 4 5]
            
             mp[sum]++;
        }
        return ans;
    }
    
};