#User function Template for python3

'''
# Node Class:
class Node:
    def init(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

# Return a list containing the inorder traversal of the given tree
class Solution:
    def inOrder(self, root):
        # code here
        inorder=[]
        curr=root
        
        while(curr!=None):
            if curr.left==None:
                inorder.append(curr.data)
                curr=curr.right
            
            else:
                prev= curr.left
                while(prev.right and prev.right!=curr):
                    prev=prev.right
                if(prev.right==None):
                    prev.right=curr
                    curr=curr.left
                else:
                    prev.right=None
                    inorder.append(curr.data)
                    curr=curr.right
        
        return inorder