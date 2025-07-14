// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>>  adj(V);
        for(auto edge : edges){
            int u=edge[0];
            int v= edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        
        st.insert({0,src});
        dist[src]=0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgn = it.second;
                if(dis+edgn < dist[adjnode]){
                    if(dist[adjnode]!=1e9){
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+edgn;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
        
    }
};