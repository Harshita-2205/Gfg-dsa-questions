class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adjl,vector<int>& vis,stack<int>& st){
        vis[node]=1;
        for(auto i :adjl[node]){
            if(!vis[i]){
                dfs(i,adjl,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjl(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjl[u].push_back(v);
        }
        stack<int> st;
        vector<int> vis(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adjl,vis,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};