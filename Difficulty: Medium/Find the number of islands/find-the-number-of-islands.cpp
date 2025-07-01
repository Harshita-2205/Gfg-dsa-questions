class Solution {
  public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid){
        int n= grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            //traverse neighours now if exists
            for(int delr=-1;delr<=1;delr++){
                for(int delc=-1;delc<=1;delc++){
                    int nr = r+delr;
                    int nc = c+delc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='L' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis (n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='L'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};