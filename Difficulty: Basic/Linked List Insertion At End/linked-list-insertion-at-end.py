'''    
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:
    def insertAtEnd(self, head, x):
        #code here
        if head is None:
            return Node(x)
    
        
        temp = head

        while(temp.next is not None):
            temp=temp.next
        
        temp.next = Node(x)
        
        return head
        