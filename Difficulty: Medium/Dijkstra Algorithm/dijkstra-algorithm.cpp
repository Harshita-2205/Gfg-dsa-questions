// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>>  adjl(V);
        for(auto edge : edges){
            int u=edge[0];
            int v= edge[1];
            int wt = edge[2];
            adjl[u].push_back({v, wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[src] =0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i : adjl[node]){
                int wt = i.second;
                int adjnode = i.first;
                if(dis+wt < dist[adjnode]){
                    dist[adjnode] = dis+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
        
    }
};