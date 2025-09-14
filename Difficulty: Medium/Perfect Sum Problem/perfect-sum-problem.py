#User function Template for python3
class Solution:
	def perfectSum(self, arr, target):
		# code here
		MOD = 10**9 + 7
        n = len(arr)
        dp = [0] * (target + 1)
        dp[0] = 1  # One way to get sum 0: empty subset
        
        # Count zeros and process non-zero elements
        zero_count = 0
        for num in arr:
            if num == 0:
                zero_count += 1
            else:
                # Update backwards from target to num for non-zero elements
                for j in range(target, num - 1, -1):
                    dp[j] = (dp[j] + dp[j - num]) % MOD
        
        # Each zero gives 2 choices: include or exclude
        # So multiply by 2^zero_count
        return (dp[target] * pow(2, zero_count, MOD)) % MOD 
		        
		        
		    