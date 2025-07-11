// User function Template for C++

class Solution {
  public:
    bool dfs(int node, vector<int> adjl[], vector<int>& vis, vector<int>& pathvis, vector<int>& check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node]=0;
        for (auto i : adjl[node]) {
            if (!vis[i]) {
                if (dfs(i, adjl, vis, pathvis, check)==true) {
                    check[node]=0;
                    return true;
                }
            } else if (pathvis[i]) {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adjl[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> check(V,0);
        vector<int> safenodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
             dfs(i, adjl, vis, pathvis, check);   
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) safenodes.push_back(i);
        }
        return safenodes;
    }
};
