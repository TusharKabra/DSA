https://leetcode.com/problems/find-median-from-data-stream/

We will use two pq, one to store the smaller half and other to store the larger half.
We will first push the element into the left. Then pop its topmost element. Insert this into the
right pq.

=======================================================================================

class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() 
    {
         
    }
    
    void addNum(int num) 
    {
        
        left.push(num);
        right.push(left.top());
        left.pop();
        if(left.size()<right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() 
    {
        if(left.size()==right.size())   //total elements are even so avg of top two elements.
            return (double)(left.top()+right.top())/2.0;
        
        else
            return left.top();
        
    }
};