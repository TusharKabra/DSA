https://leetcode.com/problems/minimum-size-subarray-sum/

Read the question carefully. The sum>=target and not only ==

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int i=0;
        int j=0;
        long long int sum=0;
        int ans=1e9;
        while(j<n)
        {
            sum+=nums[j];
            if(sum<target)
            {
                j++;
            }
            else
            {
                while(sum>=target)
                {
                    ans=min(ans,j-i+1);
                    sum=sum-nums[i];
                    i++;
                    
                    if(sum<target)
                        break;
                    
                }
                j++;
            }
            
        }
        if(ans==1e9)
            return 0;
        return ans;
        
    }
};