'''
class node:
    def __init__(data):
        self.data = data
        self.next = None
'''

class Solution:
    def getMiddle(self, head):
        # code here

        if head is None:
            return head
        if head.next is None:
            return head
            
        slow=head
        fast=head
        while(fast is not None and fast.next is not None):
            slow=slow.next
            fast = fast.next.next
        
        return slow.data
