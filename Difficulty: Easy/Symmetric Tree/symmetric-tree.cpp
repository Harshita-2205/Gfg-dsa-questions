/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool sym(Node* left,Node*right){
        if(left==NULL && right==NULL) return true;
        if (left == NULL || right == NULL) {
            return false;
        }
        if(left->data!=right->data) return false;
        
        return sym(left->left,right->right) && sym(left->right,right->left);
        
        
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root==NULL) return true;
        return sym(root->left,root->right);
    }
};