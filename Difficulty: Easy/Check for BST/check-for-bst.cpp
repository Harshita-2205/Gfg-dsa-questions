class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isvalid(Node*root,int min_val,int max_val){
        if(root==NULL) return true;
        if(root->data>=max_val || root->data<=min_val) return false;
        return isvalid(root->left,min_val,root->data) && isvalid(root->right,root->data,max_val);
    }
    bool isBST(Node* root) {
        // Your code here
        return isvalid(root,INT_MIN,INT_MAX);
        
    }
};