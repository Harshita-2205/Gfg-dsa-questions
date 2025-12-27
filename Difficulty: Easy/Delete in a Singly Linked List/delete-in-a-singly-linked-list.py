'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:
    def deleteNode(self, head, x):
        #code here
        temp = head
        
        if x==1:
            head= temp.next
            return head
            
        prev = None
        for i in range(1,x):
            prev = temp
            temp = temp.next
        
        prev.next = temp.next
        
        return head
        
