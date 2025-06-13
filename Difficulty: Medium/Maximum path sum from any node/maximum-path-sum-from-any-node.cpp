// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int maxi =  INT_MIN;
        maxpathsum(root,maxi);
        return maxi;
    }
    
    private:
        int maxpathsum(Node*root,int& maxi){
            if(root==NULL) return 0;
            
            int lsum = max(0,maxpathsum(root->left,maxi));
            int rsum = max(0, maxpathsum(root->right,maxi));
            maxi = max(maxi, lsum+rsum+root->data);
            
            return max(lsum,rsum)+ root->data;
        }
};