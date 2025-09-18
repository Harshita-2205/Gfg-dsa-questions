class Solution:
    def count(self, coins, sum):
        # code here 
        n=len(coins)
        dp=[[0]*(sum+1) for _ in range(n)]
        
       
        
        for j in range(sum+1):
            if j%coins[0]==0:
                dp[0][j]=1
            else:
                dp[0][j]=0
        
        for i in range(1,n):
            for j in range(sum+1):
                notake = dp[i-1][j]
                take =0
                if coins[i]<=j:
                    take = dp[i][j-coins[i]]
                dp[i][j]= take + notake 
        return dp[n-1][sum] 
                
