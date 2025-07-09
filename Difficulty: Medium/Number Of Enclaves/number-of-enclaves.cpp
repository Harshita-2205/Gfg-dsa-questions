// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>> &grid, int delr[],int delc[]){
        vis[r][c]=1;
        int n=grid.size();
        int m= grid[0].size();
        for(int i=0;i<4;i++){
            int nr= r+delr[i];
            int nc = c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,vis,grid,delr,delc);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m= grid[0].size();
        int delr[]={-1,0,+1,0};
        int delc[]={0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid,delr,delc);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid,delr,delc);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid,delr,delc);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid,delr,delc);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] && grid[i][j]==1){
                    grid[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
