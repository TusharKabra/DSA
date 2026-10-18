https://leetcode.com/problems/surrounded-regions/submissions/

//Grid with all "o" will give TLE if no visited array

class Solution {
public:
    bool vis[200][200]={0};
    int n,m;
    
    void dfs(vector<vector<char>>& board,int x,int y)
    {
        if(x<0||x>=n||y<0||y>=m||vis[x][y]==1||board[x][y]=='X') return;
        
        vis[x][y]=1;
        board[x][y]='#';
        dfs(board,x+1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
        dfs(board,x-1,y);
    }
    
    void solve(vector<vector<char>>& board) {
        
        n=board.size();
        m=board[0].size();
        
        //   Extreme Left and Right  Column
        for(int i=0;i<board.size();i++)
        {
                dfs(board,i,0);
                dfs(board,i,m-1);
            
        }
        
        // Extreme Up and Down Column
        for(int i=0;i<board[0].size();i++)
        {           
                dfs(board,0,i);     
                dfs(board,n-1,i);
        }
        // FLIPPING
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    
};