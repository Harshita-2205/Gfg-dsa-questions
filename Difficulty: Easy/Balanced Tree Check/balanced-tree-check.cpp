/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    bool isBalanced(Node* root) {
        return checkBalance(root) != -1;
    }

private:
    int checkBalance(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
};