class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int low = 0;
        int high = arr.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
                return mid;
            
            if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
                low = mid;
            
            else
                high= mid;
        }
        return -1;
    }
};