// User function Template for C++

class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* curr = root;
        while(curr!=NULL) {
            if(curr->left != NULL){
                Node* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;//imp 
            }
                curr=curr->right;
        }
    
    }
};