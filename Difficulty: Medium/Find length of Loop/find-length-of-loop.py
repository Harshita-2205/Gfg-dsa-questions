'''
class Node:
    def __init__(self, data): 
        self.data = data
        self.next = None
'''

class Solution:
    def lengthOfLoop(self, head):
        #code here
        slow = head
        fast = head
        
        while slow and fast and fast.next:
             slow = slow.next
             fast = fast.next.next
             
             if slow == fast:
                 cnt=1
                 temp = slow.next
                 while temp!=slow:
                     cnt+=1
                     temp = temp.next
                 return cnt
        return 0