// User function Template for C++
class Solution {
  public:
    void toposort(int node,vector<vector<pair<int, int>>>& graph,vector<int>& vis,stack<int>& st){
        vis[node] =1;
        for(auto i : graph[node]){
            int v = i.first;
            if(!vis[v]){
                toposort(v,graph,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> graph(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            graph[u].push_back({v, wt});
        }
        vector<int> vis(V,0);
        stack<int> st;
        vector<int> dist(V,INT_MAX);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposort(i,graph,vis,st);
            }
        }
        dist[0]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX) {
            for(auto i : graph[node]){
                int v = i.first;
                int wt = i.second;
                if(dist[node]+wt < dist[v]){
                    dist[v]= dist[node]+wt;
                }
            }
            }
            
        }
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
