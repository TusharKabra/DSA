https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

m=No. of boquets
k= no. of flowers in each boquet

==========================================================================
class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k)
    {
        int cnt=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                cnt++;
            }
            else
            {
                ans+=cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        return (ans>=m);
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        long long int n=bloomDay.size();
        long long int a=1;
        long long int x= (m*a*k*a);  //very important to avoid overflow
        if(x>n)
            return -1;
        
        int mi=1e9;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mi=min(mi,bloomDay[i]);
            mx=max(mx,bloomDay[i]);
        }
        
        int lo=mi;
        int hi=mx;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(possible(bloomDay,mid,m,k))
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return ans;
    }
};