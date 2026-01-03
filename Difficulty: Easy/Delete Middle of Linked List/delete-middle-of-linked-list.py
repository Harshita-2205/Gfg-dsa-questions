'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''


class Solution:

    def deleteMid(self, head):
        '''
        head:  head of given linkedList
        return: head of resultant llist
        '''

        #code here
        if head is None or head.next is None:
            return None
            
        slow = head
        fast = head
        prev = None
        while fast is not None and fast.next is not None:
            fast= fast.next.next
            prev = slow
            slow = slow.next
        prev.next =slow.next
        return head
            
            
            