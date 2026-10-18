

O(N) Space:


dp[i] stores the max sum till i including i.
--------------------------------------------------------------------------
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int mx=nums[0];
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
		    //If prefix subarray is negative for some element nums[i] 
			//then no need to include this prefix
			
            if(dp[i-1]<0)   
            {
                dp[i]=nums[i];
                
            }
			
			//else we can add our current element to the 
			//previous positive subarray and store it in dp[i]
            else
            {
                dp[i]=dp[i-1]+nums[i];
            }
            
            mx=max(mx,dp[i]);
        }
        return mx;
        
    }
};
----------------------------------------------------------------
O(1) Space optimisation:

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int mx=nums[0];
		
		//Since in the for loop we are starting with the first index so prev will not be 0.
        int prev=nums[0];
        int curr=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(prev<0)
            {
                curr=nums[i];
                
            }
            else
            {
                curr=prev+nums[i];
            }
            
            mx=max(mx,curr);
            prev=curr;
        }
        return mx;
        
    }
};
