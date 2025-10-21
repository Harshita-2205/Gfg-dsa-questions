class Solution:
    def dfs(self,adj,node,vis,st):
        vis[node]= 1
        for i in adj[node]:
            if not vis[i]:
                self.dfs(adj,i,vis,st)
        
        st.append(node)
    
    def topoSort(self, V, edges):
        # Code here
        adj=[[] for _ in range(V)]
        for u,v in edges:
            adj[u].append(v)
            
            
        st = []
        vis= [False]*V
        
        for i in range(V):
            if not vis[i]:
                self.dfs(adj,i,vis,st)
        
        ans=[]
        while(st):
            ans.append(st.pop())
        return ans            
            