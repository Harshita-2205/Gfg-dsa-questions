'''
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
from collections import deque, defaultdict
class Solution:
    
    def KDistanceNodes(self,root,target,k):
        # code here
        # return the sorted list all nodes at k distance from target
        
        res=[]
        if root is None:
            return res
        
        q=deque([root])
        mpp= {root:None}
        tar=0
        
        while q:
            curr= q.popleft()
            
            if curr.data==target:
                tar=curr
            
            if curr.left:
                mpp[curr.left]=curr
                q.append(curr.left)
            if curr.right:
                mpp[curr.right]=curr
                q.append(curr.right)
                
        q.append(tar)
        
        vis={}
        while q:
            size=len(q)
            
            if k==0:
                while q:
                    curr=q.popleft()
                    res.append(curr.data)
                break
            
            while size>0:
                node = q.popleft()
                vis[node]=True
                
                if node.left and not vis.get(node.left,False):
                    q.append(node.left)
                if node.right and not vis.get(node.right,False):
                    q.append(node.right)
                
                parent = mpp.get(node)
                if parent and not vis.get(parent,False):
                    q.append(parent)
                
                size-=1
            k-=1
        
        res.sort()
        return res
                
                
            
            