// User function Template for C++

class Solution {
  public:
   void dfs(int r,int c, vector<vector<int>>& vis, vector<vector<char>>& mat,int delr[],int delc[]){
       vis[r][c]=1;
        int n = mat.size();
        int m = mat[0].size();
    
       for(int i=0;i<4;i++){
           int nr = r+delr[i];
           int nc = c+delc[i];
           if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
               dfs(nr,nc,vis,mat,delr,delc);
           }
       }
   }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delr[]= {-1, 0 ,+1,0};
       int delc[]= {0,+1,0,-1};
        // 1st row and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat,delr,delc);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat,delr,delc);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,delr,delc);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,delr,delc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] ='X';
                }
            }
        }
        return mat;
    }
};