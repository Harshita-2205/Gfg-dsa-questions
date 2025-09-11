class Solution:
    def isSubsetSum (self, arr, sum):
        # code here 
        n = len(arr)
        
        dp = [False] * (sum + 1)
        dp[0] = True  # sum 0 is always achievable
        
        for num in arr:
            # Process backwards to avoid using same element multiple times
            for j in range(sum, num - 1, -1):
                if dp[j - num]:
                    dp[j] = True
        
        return dp[sum]
                
        
        