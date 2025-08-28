'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
from collections import deque
class Solution:
    def leftview(self,root,level,res):
        if root is None:
            return res
        
        if len(res)==level:
            res.append(root.data)
        
        self.leftview(root.left,level+1,res)
        self.leftview(root.right,level+1,res)
        
        
    def LeftView(self, root):
        # code here
        res=[]
        self.leftview(root,0,res)
        return res
        
            
        