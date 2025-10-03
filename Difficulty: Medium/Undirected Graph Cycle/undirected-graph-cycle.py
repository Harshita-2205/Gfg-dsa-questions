from collections import deque
class Solution:
	def isCycle(self, V, edges):
		#Code here
		adj = [[] for _ in range(V)]
		for u,v in edges:
		    adj[u].append(v)
		    adj[v].append(u)
		vis = [0]*V  
		def bfs_cycle(start):
            q = deque([(start, -1)])
            vis[start] = True
            
            while q:
                node, parent = q.popleft()
                for neighbor in adj[node]:
                    if not vis[neighbor]:
                        vis[neighbor] = True
                        q.append((neighbor, node))
                    elif neighbor != parent:
                        return True
            return False
        
        # Check all components
        for i in range(V):
            if not vis[i]:
                if bfs_cycle(i):
                    return True
        return False
		          
		        