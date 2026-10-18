Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

--------------------------------------------------------------
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
	{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        for (auto kv : cnt) 
		{
            pq.push({kv.second, kv.first});
            while (pq.size() > k) 
			pq.pop();
        }
		
        vector<int> res;
        while (!pq.empty()) 
		{
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};