#User function Template for python3

class Solution:
    def findways(self,arr,target):
        n= len(arr)
        
        dp = [[0] * (target + 1) for _ in range(n)]
        
        for i in range (n):
            dp[i][0]=1
        if arr[0]<= target:
            dp[0][arr[0]]=1
        if arr[0] == 0:
            dp[0][0] = 2
        for i in range(n):
            for tar in range(target+1):
                notake = dp[i-1][tar]
                take = 0
                if arr[i]<=tar:
                    take = dp[i-1][tar-arr[i]]
                dp[i][tar]= (take + notake)
        return (dp[n-1][target])
    def countPartitions(self, arr, d):
        # code here
        n= len(arr)
        total=0
        for i in range(n):
            total+=arr[i]
                
        if ((total+d) ==0 or (total+d)%2 ):
            return 0
        target = (total + d) // 2
        
        # Target should be between 0 and total
        if target < 0 or target > total:
            return 0
        return self.findways(arr,target)
    def findTargetSumWays(self, n, arr, target):
        # code here 
        return self.countPartitions( arr, target)