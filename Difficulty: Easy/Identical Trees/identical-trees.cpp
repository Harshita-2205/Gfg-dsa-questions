/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
         if (r1 == NULL && r2 == NULL) {
            return true;
        }
        // If one of the nodes is NULL and the other is not, they are not identical
        if (r1 == NULL || r2 == NULL) {
            return false;
        }
        // Check if current node data is equal and recursively check left and right subtrees
        return (r1->data == r2->data) 
            && isIdentical(r1->left, r2->left) 
            && isIdentical(r1->right, r2->right);
    }
};