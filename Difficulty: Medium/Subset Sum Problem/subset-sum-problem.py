class Solution:
    def isSubsetSum (self, arr, sum):
        # code here 
        n = len(arr)
        dp = [[False] * (sum + 1) for _ in range(n)]
        
        for i in range(n):
            dp[i][0]=True
        
        if arr[0]<=sum:
            dp[0][arr[0]]=True
        
        for i in range(1,n):
            for tar in range(1,sum+1):
                notake= dp[i-1][tar]
                take=False
                if arr[i]<=tar:
                    take= dp[i-1][tar-arr[i]]
                dp[i][tar]= take or notake
            
        return dp[n-1][sum]
                
        
        