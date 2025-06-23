/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    int helper(Node* root,int sum){
         if(root==NULL) return 0;
        sum = sum*10+root->data;
        if(root->left ==NULL && root->right==NULL) return sum;
        int lsum = helper(root->left,sum);
        int rsum = helper(root->right,sum);
        return lsum+rsum;
    }
    int treePathsSum(Node *root) {
        // code here.
       
        return helper(root,0);
    }
};