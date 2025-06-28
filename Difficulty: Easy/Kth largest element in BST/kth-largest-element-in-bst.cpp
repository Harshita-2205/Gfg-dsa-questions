/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void inorder(Node*root,int &k,int &ans){
        if(root==NULL) return ;
        int count=0;
        inorder(root->right,k,ans);
        k--;
        if(k==0){
            ans=root->data;
            return ;
        }
        inorder(root->left,k,ans);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans=-1;
        inorder(root,k,ans);
        return ans;
        
    }
};