from collections import deque, defaultdict
class Solution:
    
    def minTime(self, root, target):
        # code here 
        if root is None:
            return -1
        
        q= deque([root])
        mpp={root:None}
        tar=0
        while q:
            curr= q.popleft()
            if curr.data== target:
                tar=curr
            
            if curr.left:
                mpp[curr.left]=curr
                q.append(curr.left)
            if curr.right:
                mpp[curr.right]=curr
                q.append(curr.right)
        
        vis={}
        ans=-1
        q.append(tar)
        while q:
            size = len(q)
            for i in range(size):
                curr= q.popleft()
                vis[curr]=True
                
                if curr.left and not vis.get(curr.left, False):
                    q.append(curr.left)
                if curr.right and not vis.get(curr.right,False):
                    q.append(curr.right)
                    
                parent = mpp[curr]
                if parent and not vis.get(parent,False):
                    q.append(parent)
                
            ans+=1
        return ans
            
