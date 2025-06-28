/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void inorder(Node*root,int &k,int &ans){
        if(root==NULL) return ;
        inorder(root->left,k,ans);
        k--;
        if(k==0){
            k=INT_MAX;
            ans = root->data;
        }
        inorder(root->right,k,ans);
        
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        int ans=0;
        inorder(root,k,ans);
        if(ans==0){
            return -1;
        }
        else{
            return ans;
        }
    }
};