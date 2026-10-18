

https://leetcode.com/problems/single-threaded-cpu/discuss/2965966/C%2B%2B-or-Priority-Queue-or-Sorting


vector v=<enqueue time ,processing time,index,

priority queue pq= <processing time,index,enque time>
pq is a min heap-
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

=============================================================================