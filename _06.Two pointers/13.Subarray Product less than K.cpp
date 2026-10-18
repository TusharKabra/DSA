https://leetcode.com/problems/subarray-product-less-than-k/

Given an array of integers nums and an integer k, return the number of contiguous 
subarrays where the product of all the elements in the subarray is strictly less than k.
Constraints
1 <= nums.length <= 3 * 10^4
1 <= nums[i] <= 1000
0 <= k <= 10^6
---------------------------------------------------------------------------------------
Concept: The question is simple as there are no 0 and negative no.s.
However edge cases such as k=0 or empty subarray should be considered.


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int n=nums.size();
        long long int i=0;
        long long int j=0;
        long long int ans=0;
        long long int prod=1;
        while(j<n)
        {
            prod*=nums[j];
            if(prod<k)
            {
                ans+=j-i+1;
                j++;
            }
            else
            {
                while(prod>=k&&i<j)
                {
                    prod=prod/nums[i];
                    i++;
                    
                }
                if(prod<k)   //way to handle k=0;
                ans+=j-i+1;
                
                j++;
            }
        }
        return ans;
        
    }
};