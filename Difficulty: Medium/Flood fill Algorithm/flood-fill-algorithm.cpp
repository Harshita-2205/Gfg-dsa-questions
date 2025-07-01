class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>>& ans, vector<vector<int>>& image, int newcolor, const vector<int>& delr, const vector<int>& delc, int initialcolor){
        ans[r][c] = newcolor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0;i<4;i++){
            int nr = r+delr[i];
            int nc = c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initialcolor && ans[nr][nc]!=newcolor){
                dfs(nr,nc,ans,image,newcolor,delr,delc,initialcolor);
            }
        }
    }
  
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int intialcolor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delr = {-1, 0, 1, 0};
        vector<int> delc = {0, 1, 0, -1}; 
        dfs(sr,sc,ans,image,newColor,delr,delc,intialcolor);
        return ans;
        
    }
};