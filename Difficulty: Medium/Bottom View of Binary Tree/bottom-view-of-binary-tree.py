'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
from collections import deque

class Solution:
    def bottomView(self, root):
        # code here
        ans=[]
        if root is None:
            return ans
            
        mpp={}
        q= deque([(root,0)])
        
        while q:
            node,level = q.popleft()
            mpp[level]= node.data
            
            if node.left:
                q.append((node.left,level-1))
            if node.right:
                q.append((node.right,level+1))
            
        for level in sorted(mpp.keys()):
            ans.append(mpp[level])
        return ans
                
            
            