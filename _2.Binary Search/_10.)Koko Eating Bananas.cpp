https://leetcode.com/problems/koko-eating-bananas/


//Return the minimum integer k such that she can eat all the bananas within h hours.

class Solution {
public:
    bool solve(vector<int>&piles,int mid,int h)
    {
        long long int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            sum+=piles[i]/mid+(piles[i]%mid!=0);
        }
        return (sum<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        long long int sum=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            sum+=piles[i];
        }
        
        long long int lo=1;
        long long int hi=sum;
        long long int ans=0;
        while(lo<=hi)
        {
            long long int mid=lo+(hi-lo)/2;
            if(solve(piles,mid,h))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
            
        }
        
        return ans;
        
    }
};