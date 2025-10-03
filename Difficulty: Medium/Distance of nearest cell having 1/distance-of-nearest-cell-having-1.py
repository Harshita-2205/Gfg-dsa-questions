from collections import deque
class Solution:
    #Function to find distance of nearest 1 in the grid for each cell.
	def nearest(self, grid):
		#Code here
		n = len(grid)
		m=len(grid[0])
		dis= [[0]*m for _ in range(n)]
		vis= [[0]*m for _ in range(n)]
		q= deque()
		
		for i in range(n):
		    for j in range(m):
		        if grid[i][j]==1:
		            q.append((i,j,0))
		            vis[i][j]=1
		delr = [-1,0,1,0]
		delc = [0,1,0,-1]
		while(q):
		    r,c,dist=q.popleft()
		    dis[r][c]=dist
		    for i in range(4):
		        nr = r+delr[i]
		        nc = c+delc[i]
		        
		        if(0<=nr<n and 0<=nc<m and not vis[nr][nc] and grid[nr][nc]!=1):
		            q.append((nr,nc,dist+1))
		            vis[nr][nc]=1
		return dis