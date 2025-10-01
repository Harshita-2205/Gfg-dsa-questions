class Solution:
    def dfs(self, node, adj, vis, component):
        vis[node] = True
        component.append(node)
        for neighbor in adj[node]:
            if not vis[neighbor]:
                self.dfs(neighbor, adj, vis, component)
    
    def getComponents(self, V, edges):
        # Build adjacency list from edges
        adj = [[] for _ in range(V)]
        
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        vis = [False] * V
        components = []
        
        for i in range(V):
            if not vis[i]:
                component = []
                self.dfs(i, adj, vis, component)
                components.append(component)
        
        return components