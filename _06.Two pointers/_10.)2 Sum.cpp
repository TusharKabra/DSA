
https://leetcode.com/problems/two-sum/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[target-nums[i]]>0&&mp[target-nums[i]]!=i)
            {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
                
                
            }
            
        }
        return ans;
        
    }
};

------------------------------------------------------------------------
SINGLE PASS:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) 
		{
            if (indices.find(target - nums[i]) != indices.end()) 
			{
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};