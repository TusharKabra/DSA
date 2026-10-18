//Array contains only unique elements
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(nums[0]<=nums[n-1])
        {
            return nums[0];
        }
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<nums[0])
            {
                ans=nums[mid];
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
        
        
    }
};
