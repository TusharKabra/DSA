https://leetcode.com/problems/subarrays-with-k-different-integers/


class Solution {
public:
    int calc(vector<int>& nums, int k)
    {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            if(mp.size()<=k)
            {
                ans+=j-i+1;
                j++;
            }
            
            else if(mp.size()>k)
            {
                while(i<=j&&mp.size()>k)
                {
                    mp[nums[i]]--;
                    
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    
                    i++;
                }
                ans+=j-i+1;
                j++;
                
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int x=calc(nums,k);
        int y=calc(nums,k-1);
        return x-y;
        
    }
};