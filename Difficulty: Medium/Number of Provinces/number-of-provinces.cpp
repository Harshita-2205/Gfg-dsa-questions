// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited){
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
};