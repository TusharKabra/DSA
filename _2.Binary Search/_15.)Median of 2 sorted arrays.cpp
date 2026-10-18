https://leetcode.com/problems/median-of-two-sorted-arrays/

Two arrays:
             l1 r1
nums1= ==,==,==,==,==,==,==,==,==
nums2=    ==,==,==,==,==
             l2 r2

Suppose we make a cut in nums1. Now we know how many elements are there to the 
left of this cut in nums1. We also know the median position(n1+n2+1)/2. Thus we 
know how many elements will be from nums2 on the left side.

Since array sorted:
l1<=r1 and l2<=r2 will always be true.
For median l1<=r2 and l2<=r1


====================================
CASE-1 n1+n2=EVEN

If n1=5 and n2 =5
n=n1+n2=10 (even)
then median =(5+5+1)/2=5th position
      l1 r1
==,==,==,==,==,==,
   ==,==,==,==,==,==
      l2 r2
	  
====================================
CASE-2 n1+n2 is ODD
	  
if n1=5 and n2=6
n=5+6=11(odd)

then median=(5+6+1)/2 = 6th position

       l1,r1
 ==,==,==,==,==
 ==,==,==,==,==,==
       l2,r2
 
 max(l1,l2) will be at the 6th position
==================================================================================
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);  //extremely important otherwise runtime error in cases like  nums1=[2] and nums2=[]
        int n=n1+n2;
       
        int lo=0; //it might be that one of the array is empty,so we take no elements from it.
        int hi=n1;
        int left=(n1+n2+1)/2;//total elements on left of median.
		
        while(lo<=hi)
        {
            int cut1=lo+(hi-lo)/2;
            int cut2=left-cut1;
            
            int l1=-1e9;
            int l2=-1e9;
            int r1=1e9;
            int r2=1e9;
            
            l1=(cut1==0)?-1e9:nums1[cut1-1];
            l2=(cut2==0)?-1e9:nums2[cut2-1];
            r1=(cut1==n1)?1e9:nums1[cut1];
            r2=(cut2==n2)?1e9:nums2[cut2];
            
            if(l1<=r2&&l2<=r1)
            {
                if(n%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/(2.0);
                }
                else
                    return (max(l1,l2));
                
            }
            if(l1>r2)
            {
                hi=cut1-1;
            }
            else
                lo=cut1+1;
        }
        return 0.0;
    }
};