https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void find(vector<int>&candidates,int i,int target,vector<int>ds,vector<vector<int>>&ans)
    {
        if(i==candidates.size()&&target==0)
        {
            ans.push_back(ds);
            return ;
        } 
        if(i==candidates.size()&&target!=0)
        {
            return ;
        }
        
        if(candidates[i]<=target)
        {
            ds.push_back(candidates[i]);
            find(candidates,i,target-candidates[i],ds,ans);
            ds.pop_back();  // since we had included this element so when we return we need to remove the elements present in ds
        }
        find(candidates,i+1,target,ds,ans);
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int i=0;
        int n=candidates.size();
        vector<int>ds;//Stores the numbers which make the sum(i.e one combination at a time)
        vector<vector<int>>ans; //Stores all the possible combinations
        find(candidates,i,target,ds,ans);
        
        return ans;
    }
};

T.C= (2^t)*k  where t is target.
k due to length of structure getting pushed into the final ans.