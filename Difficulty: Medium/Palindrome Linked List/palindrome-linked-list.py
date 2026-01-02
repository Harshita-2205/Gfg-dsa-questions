'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''

class Solution:
    def isPalindrome(self, head):
        if not head or not head.next:
            return True
        # code here
        slow = head
        fast = head
        temp = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        temp2=slow
        prev = None
        
        while temp2 is not None:
            nextp = temp2.next
            temp2.next = prev
            prev=temp2
            temp2 = nextp
        curr= prev
        while curr is not None:
            if temp.data != curr.data:
                return False
            temp = temp.next
            curr = curr.next
        return True
        
             
            
        
        
        
        