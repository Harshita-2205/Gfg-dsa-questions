class Solution {
  public:
  bool dfs(int node, vector<vector<int>>& adjl,vector<int>& vis,vector<int>& pathvis){
      vis[node]=1;
      pathvis[node]=1;
      for(auto i : adjl[node]){
          if(!vis[i]){
              if(dfs(i,adjl,vis,pathvis)==true) return true;
          }
        else if(vis[i] && pathvis[i]){
                  return true;
              }
          
      }
      pathvis[node]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjl(V);
        for(auto edge : edges){
            int u = edge[0];
            int v= edge[1];
            adjl[u].push_back(v);

        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adjl,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
};