Given an array arr[]. The task is to find the inversion count of arr[]. 
Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.



https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

METHOD-1: GLOBAL VARIABLE cnt
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
     long long cnt=0;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
	
	
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return cnt;
    }
    void merge(long long arr[], int low, int mid, int high) 
    {
        vector<long long int> temp; // temporary array. Finally will be of size right-left+1.
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        //storing elements in the temporary array in a sorted manner//
    
        while (left <= mid && right <= high) 
        {
            if (arr[left] <= arr[right]) 
            {
                temp.push_back(arr[left]);
                left++;
            }
            else 
            {
                temp.push_back(arr[right]);
                cnt+=mid-left+1;
                right++;
            }
        }
    
        // if elements on the left half are still left //
    
        while (left <= mid) 
        {
            temp.push_back(arr[left]);
            left++;
        }
    
        //  if elements on the right half are still left //
        while (right <= high) 
        {
            temp.push_back(arr[right]);
            
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) 
        {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(long long arr[], int low, int high) 
    {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
    }
    

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
--------------------------------------------------------