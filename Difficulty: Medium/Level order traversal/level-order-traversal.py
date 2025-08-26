"""
class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None
"""
class Solution:
    def levelOrder(self, root):
        # Your code here
        queue = [root]
        ans =[]
        if root is None:
            return ans
        
        while len(queue)>0:
            size = len(queue)
            level=[]
            for i in range(size):
                node = queue.pop(0)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
                level.append(node.data)
            ans.append(level)
        
        return ans
        
    
    
        
        
        