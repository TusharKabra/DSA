Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., 
arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. 
Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1]




int binarySearch(int arr[], int l, int r, int x)
{
if (r >= l)
{
        int mid = l + (r - l) / 2;
 
        // If the element is present at
        // one of the middle 3 positions
        if (arr[mid] == x)
            return mid;
        if (mid >= l && arr[mid - 1] == x)
            return (mid - 1);
        if (mid <= r && arr[mid + 1] == x)
            return (mid + 1);
        
		//target smaller than mid
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 2, x);
 
        //target larger than mid
        return binarySearch(arr, mid + 2, r, x);
}
 
// We reach here when element is not present in array
return -1;
}
 