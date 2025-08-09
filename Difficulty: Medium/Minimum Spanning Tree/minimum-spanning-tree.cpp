class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for (const auto& neighbor : adj[node]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!vis[v]) {
                    pq.push({weight, v});
                }
            }
        }

        return sum;
        
    }
};