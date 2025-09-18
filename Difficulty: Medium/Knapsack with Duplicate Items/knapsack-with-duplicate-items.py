#User function Template for python3

class Solution:
    def knapSack(self, val, wt,capacity):
        # code here
        n= len(val)
        dp=[[0]*(capacity+1) for _ in range(n)]
        
        for j in range(capacity+1):
            dp[0][j] = (j//wt[0])*val[0]

        
        for i in range(1,n):
            for j in range(capacity+1):
                notake = dp[i-1][j]
                take=0
                if wt[i]<=j:
                    take = val[i] + dp[i][j-wt[i]]
                dp[i][j]= max(take,notake)
        
        return dp[n-1][capacity]