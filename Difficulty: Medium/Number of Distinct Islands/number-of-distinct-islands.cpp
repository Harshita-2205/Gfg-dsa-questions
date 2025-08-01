// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int delr[],int delc[],vector<pair<int,int>>& vec,int r0, int c0){
        vis[r][c]=1;
        vec.push_back({r-r0,c-c0});
        int n= grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int nr= r+delr[i];
            int nc= c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
               dfs(nr,nc,grid,vis,delr,delc,vec,r0,c0); 
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        int delr[]={-1,0,+1,0};
        int delc[]={0,+1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,delr,delc,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
