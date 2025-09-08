#User function Template for python3

class Solution:
    def minPathSum(self, triangle):
        # Code here
        n= len(triangle)
        dp= [[-1]*n for _ in range(n)]
        for j in range (n):
            dp[n-1][j]= triangle[n-1][j]
        for i in range(n-2,-1,-1):
            for j in range(i+1):
                d= triangle[i][j] + dp[i+1][j] if i>0 else 0
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1])
        return dp[0][0]