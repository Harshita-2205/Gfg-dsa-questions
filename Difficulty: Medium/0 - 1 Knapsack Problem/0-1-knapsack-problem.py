class Solution:
    def knapsack(self, W, val, wt):
        # code here
        n=len(wt)
        dp=[[0] * (W + 1) for _ in range(n)]
        for j in range(W+1):
            if wt[0] <= j:
                dp[0][j] = val[0]
            else:
                dp[0][j] = 0
        
        for i in range(1,n):
            for j in range(W+1):
                notake = dp[i-1][j]
                take =0
                if wt[i]<=j:
                    take = val[i] + dp[i-1][j-wt[i]]
                dp[i][j]= max(take,notake)
        return dp[n-1][W]
