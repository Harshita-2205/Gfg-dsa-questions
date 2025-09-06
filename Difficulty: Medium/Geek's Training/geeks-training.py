#User function Template for python3

class Solution:
    
        
        
    def maximumPoints(self, arr):
        # Code here
        n = len(arr)
        if n == 0:
            return 0
        
        # Track maximum points for previous day
        prev = arr[0][:]
        
        for i in range(1, n):
            curr = [0] * 3
            # Precompute the two maximum values from previous day
            max1, max2 = sorted(prev, reverse=True)[:2]
            
            for j in range(3):
                # If current activity was the maximum in previous day,
                # use the second maximum, else use the maximum
                if prev[j] == max1:
                    curr[j] = arr[i][j] + max2
                else:
                    curr[j] = arr[i][j] + max1
            
            prev = curr
        
        return max(prev)