// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        while(root!=NULL){
            if(root->data==x){
                return root->data;
            }
            if(root->data< x){
                ans = root->data;
                root=root->right;
            }
            else{
                root = root->left;
            }
        }
        return ans;
    }
};