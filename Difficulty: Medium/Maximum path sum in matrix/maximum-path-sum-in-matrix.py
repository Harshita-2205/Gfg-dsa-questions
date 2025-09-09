#User function Template for python3
class Solution:
    def maximumPath(self, mat):
        # code here
        n=len(mat)
        m=len(mat[0])
        dp=[[0]*m for _ in range(n)]
        
        for i in range(m):
            dp[n-1][i]= mat[n-1][i]
        for i in range(n-2,-1,-1):
            for j in range (m):
                dia= mat[i][j]+ dp[i+1][j-1] if j > 0 else 0
                d= mat[i][j] + dp[i+1][j] if i<n  else 0 
                r = mat[i][j] + dp[i+1][j+1] if j < m-1 else 0
                dp[i][j] = max(dia,d,r)
        
        return max(dp[0])