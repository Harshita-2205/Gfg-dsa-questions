#User function Template for python3

class Solution:
    def subseq(self,N,arr,K,index,ans):
        if ans==K:
            return True
        if ans>K:
            return False
        
        if ans<K and index==N:
            return False
            
        if self.subseq(N,arr,K,index+1,ans+arr[index]):
            return True
  
        if self.subseq(N,arr,K,index+1,ans):
            return True
        return False
        
    def checkSubsequenceSum(self, N, arr, K):
        # Code here
        return self.subseq(N,arr,K,0,0)
        