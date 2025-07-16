
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int delr[] = {-1,0,+1,0};
        int delc[] = {0,+1,0,-1};
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1) return diff;
            for(int i =0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newDiff = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if (newDiff < dist[nr][nc]) {
                        dist[nr][nc] = newDiff;
                        pq.push({newDiff, {nr, nc}});
                    }
                }
            }
        }
    }
};
