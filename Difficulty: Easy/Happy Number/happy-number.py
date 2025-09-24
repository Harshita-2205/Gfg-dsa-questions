#User function Template for python3
class Solution:
    def isHappy (self, N):
        # code here
        seen=set()
        while N!=1:
            N=sum(int(digit)**2 for digit in str(N))
            if N in seen:
                return 0
            seen.add(N)
        return 1
                
        