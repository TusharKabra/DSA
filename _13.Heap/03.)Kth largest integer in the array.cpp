https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

Input: nums = ["3","6","7","10"], k = 4
Output: "3"
Explanation:
The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
The 4th largest integer in nums is "3".


=================================================================================
SORTING SOLUTION-

class Solution {
public:
    
    bool static cmp(string a,string b)
    {
        if(a.size()!=b.size())
            return a.size()<b.size();
        else
            return a<b;  // In C++, your "compare" predicate must be a strict weak ordering.So a<=b will be error
    }
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end(),cmp);
        return nums[n-k];
    
        
    }
};


==============================================================================
Priority Queue SOLUTION-
 pq=<string_size,string>

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i].size(),nums[i]});
            if(pq.size()>k)
                pq.pop();
        }
        
        return pq.top().second;
    }
};