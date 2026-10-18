class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
		
		
        int y=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin()-1;//1ST SUBTRACT NUMS.BEGIN() AND THEN DO -1
		                                                                   //OTHERWISE ERROR
																		   
        if(x<nums.size()&&nums[x]==target)
            return {x,y};
        else
            return {-1,-1};
        
        
    }
};