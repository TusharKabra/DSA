





//Extremely bad long long int usage in the question.
===================================================================

class Solution {
public:
    long long int cnt=0;
    int reversePairs(vector<int>& nums) 
    {
        long long int n=nums.size();
        mergeSort(nums,0,n-1);
        return cnt;
        
    }
    void mergeSort(vector<int>&nums,long long int low,long long int high)
    {
	//This part is exactly same as merge sort question
        if(low>=high)
            return;
        long long int mid=low+(high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    void merge(vector<int>&nums,long long int low,long long int mid,long long int high)
    {
        long long int i=low;
        long long int j=mid+1;
        while(i<=mid)
        {
            while(j<=high&&(long long)(nums[i])>(long long)(2*(long long)(nums[j])))
            {
                j++;
            }
            cnt+=j-(mid+1);//no further +1 because the current j element is not included
            i++;
        }
        
        
        //The below part remains the exact same as merge sort
        vector<long long int>temp;
        long long int left=low;
        long long int right=mid+1;
        
        while(left<=mid&&right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++)
            nums[i]=temp[i-low];
    }
};