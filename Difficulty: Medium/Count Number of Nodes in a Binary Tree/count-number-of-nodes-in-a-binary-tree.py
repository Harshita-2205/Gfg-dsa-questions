#User function Template for python3

'''
# Node Class:
class Node:
    def init(self, val):
        self.data = val
        self.left = None
        self.right = None
'''
class Solution:
    def leftheight(self,root):
        h=0
        while root:
            h+=1
            root=root.left
        return h
    
    def rightheight(self,root):
        h=0
        while root:
            h+=1
            root=root.right
        return h
        
    def countNodes(self, root):
        #code here
        if root is None:
            return 0
        
        lh = self.leftheight(root)
        rh = self.rightheight(root)
        
        if lh==rh:
            return (1<<lh)-1
        return 1+self.countNodes(root.left) + self.countNodes(root.right)
            