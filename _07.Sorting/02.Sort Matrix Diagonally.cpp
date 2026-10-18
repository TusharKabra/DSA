https://leetcode.com/problems/sort-the-matrix-diagonally/


Bubble Sort Solution:
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        for(int k = 0; k + 1 < mat.size(); k++)
             for(int i = 0; i + 1 < mat.size(); i++)
                for(int j = 0; j + 1 < mat[i].size(); j++)
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);   
        return mat;
    }
};
-----------------------------------------------------------------
Optimised Map:

unordered_map<int, vector<int>> mp;
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            mp[i-j].push_back(mat[i][j]);
        }
    }
    
    for(int k=-(n-1);k<m;k++) {
        sort(mp[k].begin(),mp[k].end());
    }
    
    for(int i=m-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            mat[i][j]=mp[i-j].back();
            mp[i-j].pop_back();
        }
    }
    return mat;
}

-------------------------------------------------------
ALT Solution:

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, priority_queue<int,vector<int>,greater<int>>> mp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};