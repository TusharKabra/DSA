Given a sorted integer array arr, two integers k and x, return the k 
closest integers to x in the array. The result should also be sorted 
in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
---------------------------------------------------------------------------
Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

----------------------------------------------------------------------------
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>>pq;
        
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
            
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans; 
    }
};
----------------------------------------------------------------------------------
 Solution - II (2-Pointers)

We can initialize two pointers L=0 and R=n-1. Now our window size is n and contains excess elements. 
We will keep reducing the [L, R] window size till it becomes exactly equal to k. We can do this based 
on the condition - x - arr[L] <= arr[R] - x. If it is true, then it means arr[R] is farther away from 
x than arr[L] and thus we will eliminate arr[R]. Otherwise, we will eliminate arr[L].

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int L = 0, R = size(arr)-1;
        while (R - L >= k) 
            if (x - arr[L] <= arr[R] - x) R--;
            else L++;
        return vector<int>(begin(arr) + L, begin(arr) + R + 1);
    }
};

Time Complexity : O(n-k), we will keep reducing the window size from initial n to final k which will require a total of n-k comparisons.
Space Complexity : O(1)
----------------------------------------------------------------------------------------
For more optimal Binary search solutiony
https://leetcode.com/problems/find-k-closest-elements/discuss/1311197/Find-K-Closest-Elements-or-All-Possible-Approaches-Explained-w-Simple-Solutions!