#User function Template for python3

class Solution:
    def totalWays(self, n, m, grid):
        # Code 
        MOD = 10**9 + 7
        dp=[[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if grid[i][j]!=1:
                    if i==0 and j==0:
                        dp[0][0]=1
                    else:
                        up= dp[i-1][j] if i>0 else 0
                        left = dp[i][j-1] if j>0 else 0
                        dp[i][j]=(up+left)% MOD
                
        return dp[n-1][m-1]% MOD