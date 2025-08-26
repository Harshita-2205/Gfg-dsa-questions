'''
# Tree Node
class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def diameter(self, root):
        # Your code here
        self.dia=0
        def height(root):
            if root is None:
                return 0;
                
            lh =  height(root.left)
            rh = height(root.right)
            self.dia = max(self.dia,lh+rh)
            return 1 + max(lh, rh)
        height(root)    
        return self.dia
        
        