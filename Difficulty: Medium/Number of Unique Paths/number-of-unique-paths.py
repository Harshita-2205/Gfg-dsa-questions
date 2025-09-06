#User function Template for python3

   
class Solution:
    #Function to find total number of unique paths.
    def upath(self,dp,i,j):
        if i==0 and j==0:
            return 1
        if i<0 or j<0:
            return 0
            
        if dp[i][j]!= 0:
            return dp[i][j]
            
        up = self.upath(dp,i-1,j)
        left = self.upath(dp,i,j-1)
        
        dp[i][j] = up+left
        return dp[i][j]
    def NumberOfPaths(self,a, b):
        #code here
        dp=[[0]*b for _ in range(a)]
        return self.upath(dp,a-1,b-1)
        
        