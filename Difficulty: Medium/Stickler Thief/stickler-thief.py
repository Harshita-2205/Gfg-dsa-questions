class Solution:  
    def findMaxSum(self,arr):
        # code here
        n= len(arr)
        if n==1:
            return arr[0]
        prev=arr[0]
        prev2=0
        for i in range(1,n):
            take = arr[i]
            if i>1:
                take+=prev2
            notake = 0+prev
            curr= max(take,notake)
            prev2=prev
            prev=curr
        return prev