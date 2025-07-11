class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<vector<int>> adjl(n);
        vector<int> indegree(n,0);
        for(auto edge : prerequisites ){
            int u = edge[0];
            int v = edge[1];
            adjl[v].push_back(u);
            indegree[u]++;
        }
        
        
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : adjl[node]){
                indegree[i]--;
                if(indegree[i]==0){
                q.push(i);
            }
            }
        }
        return ans;
        
    }
};