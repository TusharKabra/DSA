https://leetcode.com/problems/boats-to-save-people/

You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit. 
Each boat carries at most two people at the same time, provided the sum of the weight 
of those people is at most limit.

Return the minimum number of boats to carry every given person.
---------------------------------------------------------------------------------------------

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int ans=0;
        while(i<j)
        {
            
            if(i!=j&&people[i]+people[j]<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        if(i==j)       //consider 1,1,1,1,1 and limit=2;
            ans++;
        
        return ans;
        
    }
};

Space Complexity: O(logN).

Some extra space is used when we sort people in place. 
The space complexity of the sorting algorithm depends on which 
sorting algorithm is used; the default algorithm varies from one language to another.
In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and 
Insertion Sort, with worst-case space complexity of O(logn).
------------------------------------------------------------------------------------------

Slightly cleaner soln:
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       
        // sort vector
        sort(people.begin(),people.end());
        
        int i = 0, j = people.size() - 1,cnt = 0;
        
        while(i <= j)
        {   
            // lightest person + heaviest person sum <= limit
            // they can go together
            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }
            // if sum is over the limit,
            // heaviest will go alone.
            else
                --j;
            
            ++cnt;  // number of boats
        }
        
        return cnt;
        
    }
	
};