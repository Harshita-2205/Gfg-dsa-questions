from collections import deque

class Solution:
    def fill(self, mat):
        n = len(mat)
        m = len(mat[0])
        vis = [[0] * m for _ in range(n)]
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # Check borders and mark connected 'O's
        for i in range(n):
            for j in range(m):
                if (i == 0 or i == n-1 or j == 0 or j == m-1) and not vis[i][j] and mat[i][j] == 'O':
                    # BFS for border-connected 'O's
                    queue = deque([(i, j)])
                    vis[i][j] = 1
                    
                    while queue:
                        r, c = queue.popleft()
                        for dr, dc in directions:
                            nr, nc = r + dr, c + dc
                            if (0 <= nr < n and 0 <= nc < m and 
                                not vis[nr][nc] and mat[nr][nc] == 'O'):
                                vis[nr][nc] = 1
                                queue.append((nr, nc))
        
        # Convert surrounded 'O' to 'X'
        for i in range(n):
            for j in range(m):
                if not vis[i][j] and mat[i][j] == 'O':
                    mat[i][j] = 'X'
        
        return mat