https://leetcode.com/problems/first-missing-positive/

LOGIC:
1.)-ve no.s,0, no.s greater than n do not affect our ans.
2.)Each time we just try to put the no. at its correct position by swapping it 
using the condition of nums[nums[i]-1]!=nums[i]

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
		
		//checking if elements are in their correct sorted position
        for (i = 0; i < n; ++i)
            if (nums[i] != (i+1))
                return i+1;
				
        return n+1; //worst case
    }
};