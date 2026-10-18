https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

Given an array of integers nums and a positive integer k, 
check whether it is possible to divide this array into sets 
of k consecutive numbers.
Return true if it is possible. Otherwise, return false.


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        if(n%k!=0)
            return false;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
                continue;
            while(mp[nums[i]]>0)
            {
                int j=nums[i];
                while(j<=nums[i]+k-1)
                {
                    if(mp.find(j)==mp.end())
                    {
                        return false;
                    }
                    mp[j]--;
                    if(mp[j]==0)
                        mp.erase(j);
                    
                    j++;
                }
                
            }
        }
        return true;
        
        
    }
};