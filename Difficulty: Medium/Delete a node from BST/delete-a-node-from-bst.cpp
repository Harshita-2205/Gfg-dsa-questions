class Solution {
  public:
    // Function to delete a node from BST.
    Node* findlastchild(Node* root){
        if(root->right==NULL) return root;
        
        return findlastchild(root->right);
        
    }
    Node* helper(Node* root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        Node* rchild = root->right;
        Node* lastchild =  findlastchild(root->left);
        lastchild->right = rchild;
        return root->left;
    }
    Node *deleteNode(Node *root, int X) {
        // your code goes here
        if(root==NULL) return NULL;
        if (root->data == X) {
            return helper(root);
        }
        Node* dummy = root;
        while(root!=NULL){
            if(root->data> X){
                if(root->left!=NULL && root->left->data==X){
                    root->left= helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right!=NULL && root->right->data==X){
                    root->right  = helper(root->right);
                    break;
                }
                else root= root->right;
            }
        }
        return dummy;
    }
};