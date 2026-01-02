# User function Template for Python3

# Following is the structure of node 
# class node:
#     def __init__(self):  
#         self.data = None
#         self.next = None

class Solution:
    def divide(self, head):
        # code here
        es=node()
        os=node()
        
        ee= es
        oe= os
        
        temp = head
        while temp is not None:
            if temp.data%2==0:
                ee.next = temp
                ee= ee.next
            else:
                oe.next = temp
                oe = oe.next
            
            temp = temp.next
        oe.next = None
        ee.next = os.next
        return es.next