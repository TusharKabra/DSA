
https://leetcode.com/problems/nth-magical-number/

1.) If you have to tell how many numbers less than x are divisible by n, 
then you do x/n to calculate. For example if x = 14 and n = 3 then x/n = 4 that 
means there are 4 numbers less than 14 which are divisible by 3 (i.e., 3, 6, 9, 12).

2.) So in case you are given 2 numbers n1 and n2 then you have to check for both the numbers similarly. 
For example, x = 25, n1 = 3, n2 = 4, then x/n1 = 8 (3, 6, 9, 12,15,18,21,24) and x/n2 = 6 (4, 8, 12,16,20,24), 
so the answer should be 8+6 = 14. But if u see then we have 12 and 24 repeated for n1 and n2 and these are 
nothing but the multiples of LCM of n1 and n2. And this is obvious also, the common multiples will repeat 
in both the cases, so we need to subtract common multiples.

3.) So now total will be x/n1 + x/n2 - x/LCM(a,b) = 25/3 + 25/4 - 25/12 = 8 + 6 - 2 = 12. 
And this is the maths for this question.

4.) Now to find LCM we know that n1 * n2 = LCM(n1,n2) * GCD(n1,n2)

5.) Now we just need to binary search between lowest and highest range.

6.) Lower limit will be min(n1,n2) and higher limit n * min(n1,n2)

Time Complexity: O(log(n*min(n1,n2))
======================================================================================================
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) 
    {
        long long int lo=min(a,b);
        long long int hi=n*1L*min(a,b)*1L; //very important to use 1L or runtime error
        long long int mod=(long long int)(1e9+7);
        long long int lcm=(a*b)/(__gcd(a,b));
        long long int ans=0;
        while(lo<=hi)
        {
            long long int mid=lo+(hi-lo)/2;
            long long int pos=mid/a+mid/b-mid/lcm;
            
            if(pos<n)
            {
                lo=mid+1;
            }
            else
            {
                ans=mid;
                hi=mid-1;
            }
        }
        return (int)(ans%(mod));
    }
};