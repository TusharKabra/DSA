https://leetcode.com/problems/maximum-performance-of-a-team/

Sort in decreasing order of efficiency.

Think like this- If I have set minimum efficiency worker as 9
then what is the max possible ans for this? Do this for all efficiency
values and the max among all of these.


==============================================================================
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
            
        }
        long long int mod=1e9+7;
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;  //stores the speed values.
        
        long long int mx=0;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
                  
            if(pq.size()==k)
            {
                sum=sum-pq.top();
                pq.pop();
            }
            
            sum+=v[i].second;
            mx=max(mx,1LL*sum*v[i].first);
            pq.push(v[i].second);
            
        }
        return mx%mod;
    }
};