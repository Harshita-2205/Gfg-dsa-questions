// User function template for C++

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
    Node* divide(Node* head) {
        // code here
         if (head == NULL || head->next == NULL) {
            return head;
        }
        
        Node *evenStart = NULL, *evenEnd = NULL;
        Node *oddStart = NULL, *oddEnd = NULL;
        Node *current = head;
        
        while (current != NULL) {
            if (current->data % 2 == 0) {
                if (evenStart == NULL) {
                    evenStart = current;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            } else {
                if (oddStart == NULL) {
                    oddStart = current;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }
        
        if (evenStart == NULL) {
            return oddStart;
        }
        
        evenEnd->next = oddStart;
        if (oddEnd != NULL) {
            oddEnd->next = NULL;
        }
        
        return evenStart;
    }
};