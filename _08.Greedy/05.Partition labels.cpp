https://leetcode.com/problems/partition-labels/


class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n=s.length();
        vector<int>dist(26,0);
        for(int i=0;i<n;i++)
        {
            dist[s[i]-'a']=i;
            
        }
        vector<int>ans;
        int sum=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,dist[s[i]-'a']);
            if(mx==i)
            {
                ans.push_back(mx+1-sum);
                sum=i+1;
            }
        }
        return ans;
        
    }
};