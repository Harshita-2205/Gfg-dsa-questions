// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        int n= grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        q.push({0,{src.first,src.second}});
        dist[src.first][src.second] = 0;
        int delr[] = {-1,0,+1,0};
        int delc[] = {0,+1,0,-1};
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c =it.second.second;
           if (r == dest.first && c == dest.second) {
                return dis;
            }
            for(int i=0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && dist[nr][nc]>(dis+1)){
                    dist[nr][nc]=dis+1;
                    
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};
