


//O(n^2)method

//dp[i]: {length, number of LIS which ends with nums[i]}

int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
         /* count and length */
        vector<pair<int, int>>LIS(n, {1, 1}); 
        int maxlen = 0;
        for (int i = 0; i < n; i++) 
		{
            for (int j = 0; j < i; j++) 
			{
                if (nums[i] > nums[j]) 
				{
                    if (LIS[i].second == 1 + LIS[j].second) 
					{
                        LIS[i].first += LIS[j].first;
                    } 
					else if (LIS[i].second < 1 + LIS[j].second) 
					{
                        LIS[i].first = LIS[j].first;
                        LIS[i].second = 1 + LIS[j].second;
                    }
                }
            }
            maxlen = max(maxlen, LIS[i].second);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i].second == maxlen)
                ans += LIS[i].first;
        }
        
        return ans;
    }