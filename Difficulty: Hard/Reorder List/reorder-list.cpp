/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void reorderList(Node* head) {
        // Your code here
        Node* fast = head;
        Node * slow = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* second = slow->next;
        slow->next = NULL;
        Node * prev = NULL;
        
        while(second!=NULL){
            Node*temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        
        Node* first = head;
        second = prev;
        
        while(second!=NULL){
            Node*t1 = first->next;
            Node*t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    
        
    }
};