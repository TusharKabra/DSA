
 
//Merge done in Postorder
//Stable
//Not in Place
------------------------------------------------------------------  
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array. Finally will be of size right-left+1.
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}
------------------------------------
SOME ANALYSIS:

Before Sorting Array: 
arr[]= 9 4 7 6 3 1 5 

Iteration 1
4 9 7 6 3 1 5 
Iteration 2
4 9 6 7 3 1 5 
Iteration 3
4 6 7 9 3 1 5 
Iteration 4
4 6 7 9 1 3 5 
Iteration 5
4 6 7 9 1 3 5 
Iteration 6
1 3 4 5 6 7 9
------------------------------------
TEMP ARRAY:

Iteration 1
LOW: 0 HIGH:1
4 9 
Iteration 2
LOW: 2 HIGH:3
6 7 
Iteration 3
LOW: 0 HIGH:3
4 6 7 9 
Iteration 4
LOW: 4 HIGH:5
1 3 
Iteration 5
LOW: 4 HIGH:6
1 3 5 
Iteration 6
LOW: 0 HIGH:6
1 3 4 5 6 7 9 
=============================================
Following Snippet:(Count inversions)

 while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
            cnt+=mid-left+1;
        }
    }
    cout<<"Iteration"<<c<<" "<<cnt<<endl;
    c++;
	
Output:
Iteration0 1
Iteration1 2
Iteration2 4
Iteration3 5
Iteration4 5
Iteration5 16