#User function Template for python3
class Solution:
	def perfectSum(self, arr, target):
		# code here
		n=len(arr)
        MOD = 10**9 + 7
        dp = [[0] * (target + 1) for _ in range(n)]
        for i in range(n):
            dp[i][0]=1
        
        if arr[0]<= target:
            dp[0][arr[0]]=1
        if arr[0] == 0:
            dp[0][0] = 2
            
        
        
        for i in range(1,n):
            for tar in range(target+1):
                notake = dp[i-1][tar]
                take = 0
                if arr[i]<=tar:
                    take = dp[i-1][tar-arr[i]]
                dp[i][tar]=(take + notake) % MOD
                
        return dp[n-1][target]  % MOD 
		        
		        
		    