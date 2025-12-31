"""
class Node:
    def __init__(self, data):   
        self.data = data
        self.next = None
"""

class Solution:
    def cycleStart(self, head):
        #code here
        slow = head
        fast = head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                slow = head
                while slow!=fast:
                    slow=slow.next
                    fast= fast.next
                return slow.data
        return -1
        