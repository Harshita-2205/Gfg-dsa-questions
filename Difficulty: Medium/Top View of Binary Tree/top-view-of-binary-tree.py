# Tree Node
# class Node:
#     def __init__(self, val):
#         self.right = None
#         self.data = val
#         self.left = None

class Solution:
    #Function to return a list of nodes visible from the top view 
    #from left to right in Binary Tree.
    def topView(self,root):
        # code here
        if root is None:
            return []
        
        ans = []
        mpp = {}
        min_level = max_level = 0
        q = deque([(root, 0)])
        
        while q:
            node, vlevel = q.popleft()
            
            if vlevel not in mpp:
                mpp[vlevel] = node.data
            
            # Update min and max levels
            min_level = min(min_level, vlevel)
            max_level = max(max_level, vlevel)
                
            if node.left:
                q.append((node.left, vlevel - 1))
                
            if node.right:
                q.append((node.right, vlevel + 1))
                
        # Iterate from min to max level to avoid sorting
        for level in range(min_level, max_level + 1):
            ans.append(mpp[level])
        
        return ans
                