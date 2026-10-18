https://leetcode.com/problems/fruit-into-baskets/

//Basically longest subarray with maximum 2 different elements.

class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        int i=0;
        int j=0;
        int n=fruits.size();
        unordered_map<int,int>mp;
        int ans=0;
        
        while(j<n)
        {
            mp[fruits[j]]++;
            if(mp.size()<=2)
            {
                ans=max(ans,j-i+1);
                
            }
            else
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    i++;
                }
                ans=max(ans,j-i+1);
            }
            j++;
                
        }
        return ans;
        
    }
};