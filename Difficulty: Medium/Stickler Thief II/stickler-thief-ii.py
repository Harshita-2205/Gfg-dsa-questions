class Solution:
    def maxsum(self,arr):
        n=len(arr)
        prev=arr[0]
        prev2=0
        for i in range(1,n):
            take =arr[i]
            if i>1:
                take += prev2
            notake =0+prev
            curr = max(take,notake)
            prev2=prev
            prev=curr
        return prev
    def maxValue(self, arr):
        # code here
        n=len(arr)
        if n==1:
            return arr[0]
        temp1=[]
        temp2=[]
        for i in range(n):
            if i!=0:
                temp1.append(arr[i])
            if i!=n-1:
                temp2.append(arr[i])
        
        return max(self.maxsum(temp1), self.maxsum(temp2))
        
        
        
