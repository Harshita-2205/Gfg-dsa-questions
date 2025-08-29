class Solution:
    def ra(self,arr,l,r):
        if l>=r:
            return
        arr[l],arr[r]=arr[r],arr[l]
        self.ra(arr,l+1,r-1)
        
    def reverseArray(self, arr):
        # code here
        l=0
        r=len(arr)-1
        self.ra(arr,l,r)
        return arr
        
        
        