
https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        queue<vector<int>>q;
        q.push({0});
        vector<vector<int>>ans;
        while(!q.empty())
        {
            vector<int>currLevel=q.front();
            q.pop();
            int node=currLevel.back();
            for(auto it:graph[node])
            {
                if(it==n-1)
                {
                    currLevel.push_back(n-1);
                    ans.push_back(currLevel);
                    currLevel.pop_back();
                    
                }
                else
                {
                    currLevel.push_back(it);
                    q.push(currLevel);
                    currLevel.pop_back();
                }
            }
        }
        return ans;
        
    }
};

=========================================================================

DFS METHOD

class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur) 
    {
        path.push_back(cur);
        
        if (cur == graph.size() - 1)
            res.push_back(path);
        
        else 
        {
            for (auto it: graph[cur])
            {
                dfs(graph, res, path, it);
            }
        }
            
        
        path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0);
        return paths;
    }
};
};