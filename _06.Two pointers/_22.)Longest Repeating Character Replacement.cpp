
https://leetcode.com/problems/longest-repeating-character-replacement/

COncept: In each window keep track of the largest freq of one element and subtract that frfom the 
window size(j-i+1). Then check if remaining number of char less than k or not.
----------------------------------------------------------------------

SOLUTION1: Less optimised:

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int i=0;
        int j=0;
        int ans=0;
        int n=s.length();
        vector<int>freq(30,0);
        
        
        while(j<n)
        {
            freq[s[j]-'A']++;
            int mx=0;
            for(int l=0;l<30;l++)
            {
                mx=max(mx,freq[l]);
            }
            
            if(j-i+1-mx<=k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
               
                while(j-i+1-mx>k)
                {
                    freq[s[i]-'A']--;
                    i++;
                    for(int i=0;i<30;i++)
                    {
                        mx=max(mx,freq[i]);
                    }
                     
                    if(j-i+1-mx<=k)
                    {
                        ans=max(ans,j-i+1);
                        j++;
                        break;
                    }
                    
                }
            }
        }
        
        return ans;
        
        
    }
};
------------------------------------------------------------------------

SOLUTION2: Optimed on Solution-1


class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int i=0;
        int j=0;
        int ans=0; //global max
        int n=s.length();
        vector<int>freq(30,0);
        int mx=0;  //local max freq of any char in a window
        
        while(j<n)
        {
            freq[s[j]-'A']++;
            mx=max(mx,freq[s[j]-'A']);
            
            if(j-i+1-mx<=k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
               
                while(j-i+1-mx>k)
                {
                    freq[s[i]-'A']--;
                    mx=max(mx,freq[s[j]-'A']);
                    i++;
                    
                
                    if(j-i+1-mx<=k)
                    {
                        ans=max(ans,j-i+1);
                        j++;
                        break; //very important
                    }
                    
                }
            }
        }
        
        return ans;
        
        
    }
};
----------------------------------------------
CLEAN:
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;//->window start
        int j=0;//->window end
        int maxC=0;//->max no of repeating elements 
        int ans=-1;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxC=max(maxC,mp[s[j]]);
            
            int curr_len=j-i+1;//Curr Len of the window
            if(curr_len-maxC>k) //the curr window has more than k replacable items case
            {
                mp[s[i]]--;
                i++;// shrinking the window
            }
            curr_len=j-i+1;// just in case i is changed
            ans=max(ans,curr_len);
            j++;
        }
        
        return ans;
    }
};
