#User function Template for python3
class Solution:
    def hei(self,i,height,dp):
        if i==0:
            return 0
        if dp[i]!=-1:
            return dp[i]
        
        left = self.hei(i-1,height,dp) + abs(height[i]-height[i-1])
        right = float('inf')
        if i>1:
            right = self.hei(i-2,height,dp) + abs(height[i]-height[i-2])
        
        dp[i] = min(left,right)
        return dp[i]
        
    
    def minCost(self, height):
        # code here
        n=len(height)
        dp=[-1]*n
        return self.hei(n-1,height,dp)