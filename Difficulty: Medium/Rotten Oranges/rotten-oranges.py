from collections import deque
class Solution:
	def orangesRotting(self, mat):
		#Code here
		n=len(mat)
		m=len(mat[0])
	
		vis = [[0]*m for _ in range(n)]
		q= deque()
		for i in range(n):
		    for j in range(m):
		        if mat[i][j]==2:
		            q.append((i, j, 0))
		            vis[i][j]=2
		            
		delr = [-1,0,+1,0]
		delc = [0,+1,0,-1]
		min_t = 0
		
		while(q):
		    size = len(q)
		    r,c,t = q.popleft()
		    min_t = max(min_t,t)
		    
		    for i in range(4):
		        nr = r+delr[i]
		        nc = c+delc[i]
		        
		        if (nr >= 0 and nr < n and nc >= 0 and nc < m and mat[nr][nc] == 1 and vis[nr][nc] != 2):
		            vis[nr][nc]=2
		            q.append((nr,nc,t+1))
		 
		for i in range(n):
		    for j in range(m):
		        if vis[i][j]!=2 and mat[i][j]==1:
		            return -1
		
		return min_t
		 
		
		
		 
		 
		 
		