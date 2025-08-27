'''
class Node:
    def _init_(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def isIdentical(self,root1, root2):
        # code here
        if root1 is None and root2 is None:
            return True
        
        # Base case: one tree is empty, the other is not
        if root1 is None or root2 is None:
            return False
        
        # Check if current nodes have same data and recursively check left and right subtrees
        return (root1.data == root2.data) and \
               self.isIdentical(root1.left, root2.left) and \
               self.isIdentical(root1.right, root2.right)