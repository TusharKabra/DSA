https://leetcode.com/problems/3sum/

Given an integer array nums, return all the 
triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
----------------------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i+2<n;i++)
        {
            int start=i+1;
            int end=n-1;
            while(start<end)
            {
                int sum=nums[i]+nums[start]+nums[end];
                if(sum>0)
                {
                    end--;
                }
                else if(sum<0)
                {
                    start++;
                }
                
                else
                {
                    vector<int>trips;
                    trips.push_back(nums[i]);
                    trips.push_back(nums[start]);
                    trips.push_back(nums[end]);
                    
                    res.push_back(trips);
                    //Important to avoid duplicate triplets
                    while(start<n&&nums[start]==trips[1])
                        start++;
                    while(end>=0&&nums[end]==trips[2])
                        end--;
                }
            }
            while(i+2<n&&nums[i]==nums[i+1])
                i++;
        }
        return res;
        
    }
};