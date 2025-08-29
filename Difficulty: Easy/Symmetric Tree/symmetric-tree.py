'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def sym(self,r1,r2):
        if r1==None or r2==None:
            return r1==r2
        
        return r1.data==r2.data and  self.sym(r1.left,r2.right) and self.sym(r1.right,r2.left)
        
    def isSymmetric(self, root):
        #Code Here
        if root is None:
            return True
        
        return self.sym(root.left,root.right)
        
        
        