#User function Template for python3

class Solution:
    def isPossible(self, a, b):
        #Code here
        if ((a == 2 and (b == 1 or b == 3)) or (b == 2 and (a == 1 or a == 3))):
            return True
        return False