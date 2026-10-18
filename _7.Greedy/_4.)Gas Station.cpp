https://leetcode.com/problems/gas-station/

1.)If the total sum of (gas[i]-cost[i]) is less than zero then not possible

2.)Also take a variable currsum. If that becomes 0 at any time,
it means that the index before it can surely be not in the answer. Move the pos to next index.

================================================================================================
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n=gas.size();
        
        int sum=0;
        int currsum=0;
        int pos=0;
        for(int i=0;i<n;i++)
        {
            sum+=gas[i]-cost[i];
            currsum+=gas[i]-cost[i];
            
            if(currsum<0)
            {
                pos=i+1;
                currsum=0;
            }
        }
        if(sum<0||pos==n)
            return -1;
        else
            return pos;
        
    }
};