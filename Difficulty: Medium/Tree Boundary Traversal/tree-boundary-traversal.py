'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def isleafnode(self,root):
            return root.left==None and root.right==None
            
    def leftboun(self,root,res):
        curr=root.left
        while curr:
            if not self.isleafnode(curr):
                res.append(curr.data)
            
            if curr.left:
                curr=curr.left
            else:
                curr=curr.right
    
    def rightboun(self,root,res):
        curr=root.right
        temp=[]
        while curr:
            if not self.isleafnode(curr):
                temp.append(curr.data)
            if curr.right:
                curr=curr.right
            else:
                curr=curr.left
                
        
        for i in range(len(temp)-1,-1,-1):
            res.append(temp[i])
        
    def addleafs(self,root,res):
        if self.isleafnode(root):
            res.append(root.data)
        
        if root.left:
            self.addleafs(root.left,res)
        
        if root.right:
            self.addleafs(root.right,res)
    
    
    def boundaryTraversal(self, root):
        # Code here
        res=[]
        if not root:
            return res
        
        if not self.isleafnode(root):
            res.append(root.data)
        
        self.leftboun(root,res)
        self.addleafs(root,res)
        self.rightboun(root,res)
        
        return res
        
        
            
                