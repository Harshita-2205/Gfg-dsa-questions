
class Solution:
    
    def countWays(self, n):
        # code here
        if n == 0:
            return 1
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        # Initialize dp array
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[n]
            
            
            
        
        
      
      
        
        