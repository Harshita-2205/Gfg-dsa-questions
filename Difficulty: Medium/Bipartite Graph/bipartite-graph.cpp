class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
         vector<vector<int>> adjl(V);
        for(auto edge : edges){
            int u =edge[0];
            int v= edge[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        vector<int> color(V,-1);
        queue<int> q;
        q.push(0);
        color[0]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adjl[node]){
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[node]==color[it]){
                    return false;
                }
            }
        }
        return true;
    }
};