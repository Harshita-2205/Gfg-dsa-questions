class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,int vis[],vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int vis[adj.size()] = {0};
        int start = 0;
        vector<int> ans;
        dfs(start,adj,vis,ans);
        return ans;
    }
};