class Solution:
    def pal(self,s,l):
        if l>=len(s)//2:
            return True
        if s[l]!=s[len(s)-l-1]:
            return False
     
        return self.pal(s,l+1)
 
    def isPalindrome(self, s):
        # code here
        return self.pal(s,0)
        
        
