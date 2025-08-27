'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
from collections import deque, defaultdict

class Solution:
    
    def verticalOrder(self, root): 
        #Your code here
        if not root:
             return []
         # Use defaultdict with list to store nodes at each vertical level
        vertical_map = defaultdict(list)
        
        # Queue stores (node, vertical_level)
        q = deque()
        q.append((root, 0))
        
        min_level = max_level = 0
        
        while q:
            node, level = q.popleft()
            vertical_map[level].append(node.data)
            
            min_level = min(min_level, level)
            max_level = max(max_level, level)
            
            if node.left:
                q.append((node.left, level - 1))
            if node.right:
                q.append((node.right, level + 1))
        
        # Collect results from leftmost to rightmost vertical level
        result = []
        for level in range(min_level, max_level + 1):
            result.append(vertical_map[level])
        
        return result