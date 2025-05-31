/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node* fast = head;
        Node * slow = head;
        
        for(int i=0;i<k;i++){
            if(fast==NULL){
                return -1;
            }
            fast = fast->next;
        }
        
        while(fast!=NULL){
            slow= slow->next;
            fast= fast->next;
            
        }
        return slow->data;
        
        
    }
};