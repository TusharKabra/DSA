
Q)
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].


class Solution {
public:
    
    //STARTING POSITION OF THE ELEMENT
	
    int BSStart(vector<int>& nums, int target,int n)
    {
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                end=mid-1;
                
            }
            if(nums[mid]<target)
            
                start=mid+1;
            
            else if(nums[mid]>target) //WRITE THIS AND NOT JUST ELSE!!!
                end=mid-1;
        }
        return ans;
    }
    
	//ENDING POSITION OF THE ELEMENT
	
    int BSEnd(vector<int>& nums, int target,int n)
    {
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
                
            }
            if(nums[mid]<target)
                start=mid+1;
            
            else if(nums[mid]>target)
                end=mid-1;
        }
        return ans;
    }
	
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n=nums.size();
        if(n==0)
            return {-1,-1};
        int start=0;
        int end=n-1;
        start=BSStart(nums,target,n);
        end=BSEnd(nums,target,n);
        
        return {start,end};
        
        
    }
};
