// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
             int n = dist.size();
        const int INF = 1e8; // Represents infinity as per the problem statement
        
        // Initialize the distance matrix: set diagonal to 0 and leave others as is
        for (int i = 0; i < n; ++i) {
            if (dist[i][i] != 0) {
                dist[i][i] = 0;
            }
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }
        
    }
};