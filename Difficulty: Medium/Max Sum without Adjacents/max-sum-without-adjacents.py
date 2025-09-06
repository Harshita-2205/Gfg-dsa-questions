#User function Template for python3
class Solution:
	def maxsum(self,arr,dp,ind):
	    n= len(arr)
		if ind==0:
		    return arr[0]
		if ind<0:
		    return 0
	
		if dp[ind]!=-1:
		    return dp[ind]
		pick = arr[ind]+self.maxsum(arr,dp,ind-2)
		notpick = 0+self.maxsum(arr,dp,ind-1)
		dp[ind] = max(pick,notpick)
		return dp[ind]
	    
	def findMaxSum(self,arr):
		# code here
	    n= len(arr)
		dp=[-1]*(n)
		return self.maxsum(arr,dp,n-1)
		
		   
		
		