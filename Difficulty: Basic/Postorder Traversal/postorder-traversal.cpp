/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    void postordersolve(Node* root,vector<int>&ans){
        if (root==NULL) return ;
        postordersolve(root->left,ans);
        postordersolve(root->right,ans);
        ans.push_back(root->data);
    }
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        vector<int> ans;
        postordersolve(root,ans);
        return ans;
    }
};