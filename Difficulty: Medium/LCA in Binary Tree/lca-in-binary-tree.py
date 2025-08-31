'''
class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None
'''

class Solution:
    def lca(self,root, n1, n2):
        # Code here
        if root is None:
            return None
        if root.data == n1 or root.data == n2:
            return root
        
        left = self.lca(root.left,n1,n2)
        right= self.lca(root.right,n1,n2)
        
        if left==None:
            return right
        elif right==None:
            return left
        else:
            return root
        
        

