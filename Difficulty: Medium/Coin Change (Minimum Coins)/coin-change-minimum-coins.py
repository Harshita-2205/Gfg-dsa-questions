class Solution:
	def minCoins(self, coins, sum):
		# code here
		n=len(coins)
		dp=[[0]*(sum+1) for _ in range(n)]
	    
	    for i in range(sum+1):
	        if i%coins[0] ==0:
	            dp[0][i]=i//coins[0]
	        else:
	            dp[0][i]=float('inf')
	           
	    for i in range(1,n):
	        for j in range(sum+1):
	            notake = dp[i-1][j]
	            take = float('inf')
	            if coins[i]<=j:
	                take = 1+ dp[i][j-coins[i]]
	            dp[i][j]= min(take,notake)
	    return dp[n-1][sum] if dp[n-1][sum] != float('inf') else -1
	                