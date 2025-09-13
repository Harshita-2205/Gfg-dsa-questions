#User function Template for python3
class Solution:
	def minDifference(self, arr):
		# code here
		n=len(arr)
		total=0
		for i in range(n):
		    total+=arr[i]
		dp = [[False] * (total + 1) for _ in range(n)]
		for i in range(n):
		    dp[i][0]=True
		 
	    if arr[0]<=total:
	        dp[0][arr[0]]=True
	    for i in range(1,n):
	        for tar in range(1,total+1):
	            notake = dp[i-1][tar]
	            take = False
	            if arr[i]<=tar:
	                take=dp[i-1][tar-arr[i]]
	            dp[i][tar]= take or notake
	            
	    mini=float('inf')
	    for s1 in range ((total//2)+1):
	        if dp[n-1][s1]==True:
	            mini = min(mini, abs((total - s1)-s1))
	    return mini
        
		
		