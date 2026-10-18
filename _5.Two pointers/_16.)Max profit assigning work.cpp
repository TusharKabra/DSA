https://leetcode.com/problems/most-profit-assigning-work/

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately
------------------------------------------------------------------------------------------------
ALGO:
Sort the workers array
Club the diffic and profit and sort according to diffic.
Now for each worker calc the max profit he can earn and keep adding the associated max profit.

-------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        sort(worker.begin(),worker.end());
        
        vector<vector<int>>x;
        for(int i=0;i<profit.size();i++)
        {
            x.push_back({difficulty[i],profit[i]});
        }
        
        sort(x.begin(),x.end());
        int i=0;
        int j=0;
        int c=0;
        int ans=0;
        for(i=0;i<worker.size();i++)
        {
            
            while(j<difficulty.size()&&x[j][0]<=worker[i])
            {
                c=max(c,x[j][1]);
                j++;
            }
			
            ans+=c;
            
        }
        
        
        return ans;
        
    }
};