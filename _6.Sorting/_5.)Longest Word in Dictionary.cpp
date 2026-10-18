https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/


Given a string s and a string array dictionary, return the longest string 
in the dictionary that can be formed by deleting some of the given string 
characters. If there is more than one possible result, return the longest 
word with the smallest lexicographical order. If there is no possible result, 
return the empty string.
------------------------------------------------------------------------
Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

-----------------------------------------------------------------------------
Sorting soln also there but this is better;


class Solution {
public: 
   
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        int n=s.length();
        int mx=0;
        string ans="";
        for(int i=0;i<dictionary.size();i++)
        {
            int k=0;
            int j=0;
            int m=dictionary[i].size();
            while(k<n&&j<m)
            {
                if(s[k]==dictionary[i][j])
                {
                    k++;
                    j++;
                }
                else
                {
                    k++;
                }
            }
            if(j==m)
            {
                if(m>mx)
                {
                    ans=dictionary[i];
                    mx=m;
                }
                else if(m==mx)
                {
                    ans=min(ans,dictionary[i]);
                }
            }
        }
        
        return ans;

    }
};