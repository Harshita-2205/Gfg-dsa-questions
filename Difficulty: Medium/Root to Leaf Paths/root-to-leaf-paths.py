from typing import Optional
from collections import deque

from typing import List

"""

definition of binary tree node.
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
"""

class Solution:
    def getpath(self,root,curr_path,ans):
        if root is None:
            return 
        curr_path.append(root.data)
        if root.left==None and root.right==None:
            ans.append(list(curr_path))
        else:
            self.getpath(root.left,curr_path,ans)
            self.getpath(root.right,curr_path,ans)
        curr_path.pop()
        
    
    def Paths(self, root):
        # code here
        ans=[]
        if root is None:
            return ans
        curr_path=[]
        self.getpath(root,curr_path,ans)
        return ans
        