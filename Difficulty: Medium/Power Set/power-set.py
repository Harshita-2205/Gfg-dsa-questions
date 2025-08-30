#User function Template for python3

class Solution:
    def subseq(self,s,index,curr,ans):
        if index == len(s):
            if curr:
                ans.append(''.join(curr))
            return 
        
        self.subseq(s,index+1,curr,ans)
        self.subseq(s,index+1,curr+[s[index]] ,ans)
        
        return ans
        
        
        
	def AllPossibleStrings(self, s):
		# Code hereub
		ans=[]
		self.subseq(s,0,[],ans)
		ans.sort()
		return ans