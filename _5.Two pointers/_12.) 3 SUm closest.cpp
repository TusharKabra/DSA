https://leetcode.com/problems/3sum-closest/discuss/1179560/C%2B%2B-oror-Two-Pointer-Approach-oror-3-Sum-Variation

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int mi=1e9;
        
        for(int i=0;i+2<n;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<mi)
                {
                    mi=abs(sum-target);
                    ans=sum;
                }
                if(sum<target)
                {
                    j++;
                }
                else if (sum>target)
                {
                    k--;
                }
                else //very important otherwise TLE
                    return sum;
            }
        }
        return ans;
        
    }
};