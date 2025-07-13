class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        queue<int> q;
        vector<int> dist(n,-1);
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (int i : adj[node]) {
                if (dist[i] == -1) {
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
        return dist;
    }
};