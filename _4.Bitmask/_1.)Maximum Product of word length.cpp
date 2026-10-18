https://leetcode.com/problems/maximum-product-of-word-lengths/

Given a string array words, return the maximum value of 
length(word[i]) * length(word[j]) where the two words do 
not share common letters. If no such two words exist, return 0.

---------------------------------------------------------------------
ALGO
Mask each word for easy comparison

For eg. 
Consider word1 = "abex", word2 = "acdx"
hash1 = (11001000000000000000000100) in binary
hash2 = (10110000000000000000000100) in binary
       ------------------------------------
	   & 10000000000000000000000100    ==>   common letters are present
	   
Consider word1 = "abex", word2 = "dfgmn"
hash1 = (11001000000000000000000100) in binary
hash2 = (00010110000011000000000000) in binary
       ------------------------------------
	   & 00000000000000000000000000   ==>    no common letter present
	   
So, we can just do (hash1 & hash2) and if its 0, that denotes that hash1 and hash2 didn't have 
any common set bit 
--------------------------------------------------------------------------------------

class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int n=words.size();
        vector<int>mask(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                mask[i]=mask[i]|(1<<(words[i][j]-'a'));
            }
        }
        
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((mask[i]&mask[j])==0)
                {
                    int a=(words[i].length()*words[j].length());
                    mx=max(mx,a);
                }
            }
        }
        return mx;
    }
};