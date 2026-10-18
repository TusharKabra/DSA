https://leetcode.com/problems/contiguous-array/

SEE THIS FOR EXPLANATION:
https://leetcode.com/problems/contiguous-array/discuss/653541/Python-HashMap-solution-%2B-Thinking-Process-Diagram


class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        map <int,int> mp;
        int mx = 0;
        int cnt = 0;
        
        mp[0] =0;//very important                          
        for(int i=0;i<nums.size();i++) 
        {
            if(nums[i]) 
                cnt++;                       
            else        
                cnt--; 
			
            if(mp.find(cnt) != mp.end()) 
                mx=max(mx,i+1-mp[cnt]);
            else 
                mp[cnt] = i+1;
        }
        
        return mx;
    }
};