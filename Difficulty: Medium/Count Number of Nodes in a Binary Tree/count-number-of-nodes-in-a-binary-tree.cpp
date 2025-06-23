// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root) {
        // Write your code here
        if(root==NULL) return 0;
        
        int lh = leftheight(root);
        int rh = rightheight(root);
        
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int leftheight(Node* root){
        int h=0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }
    int rightheight(Node* root){
        int h=0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
    
    
};