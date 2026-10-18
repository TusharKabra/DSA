
https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int i=1;
        int mx=0;
        int c=0;int co=0;
        while(i<n)
        {
            
            c=0; co=0;
            while(i<n&&arr[i-1]<arr[i])
            {
                c++;
                i++;
            }
            while(i<n&&arr[i-1]>arr[i])
            {
                i++;
                co++;
                
            }
            
            if(c>0&&co>0)
                mx=max(mx,c+co+1);
            
            while(i<n&&arr[i]==arr[i-1])
                i++;
           
        }
        return mx;
    }
};