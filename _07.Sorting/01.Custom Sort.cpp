
https://leetcode.com/problems/custom-sort-string/


//OPTIMAL SOLUTION:
ALGO:
1.)1st store the freq of each char of string s in freq array.
2.)Traverse over the order string and then keep pushing the char in the answer string.
Make the freq of traversed char to be 0.
3.)Insert remaining char which were not present in array
--------------------------------------------------------------------------------

class Solution {
public:
    string customSortString(string order, string s) 
    {
        int n=s.length();
        int freq[27]={0};
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        
        //order does not have all char in string s so first 
        //store all the char in order which are also there in string s.
		
        string ans="";
        for(int i=0;i<order.size();i++)
        {
            for(int j=0;j<freq[order[i]-'a'];j++)
            {
                ans.push_back(order[i]);
            }
            freq[order[i]-'a']=0;
        }
        
        
        //Remaining char which were not present in array
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<freq[i];j++)
            {
                ans.push_back((char)(i+'a'));
            }
        }
        return ans;
        
    }
};