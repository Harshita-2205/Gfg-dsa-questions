'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''
class Solution:
    def removeLastNode(self, head):
        # code here
        if head is None:
            return head
        if head.next is None:
            head = None
            return head
        prev = None
        temp = head
        while(temp.next is not None):
            prev = temp
            temp=temp.next
        
        prev.next = None
        return head
        
        
        