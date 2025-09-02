'''
# Node Class:
class Node:
    def init(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def isSumProperty(self, root):
        # code here
        if root is None or (root.left is None and root.right is None) :
            return True
        
        left=0
        right=0
        if root.left:
            left=root.left.data
        if root.right:
            right=root.right.data
        
        tot=left+right
        if tot==root.data and self.isSumProperty(root.left) and self.isSumProperty(root.right):
            return True
        return False
            
            
    