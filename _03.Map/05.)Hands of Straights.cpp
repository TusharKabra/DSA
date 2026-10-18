https://leetcode.com/problems/hand-of-straights/

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]


Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
======================================================================

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n=hand.size();
        map<int,int>mp;
        if(n%groupSize!=0)
            return false;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        
        for(auto it:mp)
        {
            int x=it.first;
            //cout<<x<<endl;
            while(mp[x]>0)
            {
                mp[x]--;
                for(int i=x+1;i<x+groupSize;i++)
                {
                    if(mp[i]==0)
                        return false;
                    else
                        mp[i]--;
                }
            }
        }
        return true;
        
    }
};

==========================================================
Slightly more optimised-

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n=hand.size();
        map<int,int>mp;
        if(n%groupSize!=0)
            return false;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        
        for(auto it:mp)
        {
            int x=it.first;
            
            if(mp[x]>0)
            {
                
                for(int i=x+1;i<x+groupSize;i++)
                {
                    if(mp[i]<mp[x])
                        return false;
                    else
                        mp[i]-=mp[x];
                }
                mp[x]=0;
            }
        }
        return true;
        
    }
};