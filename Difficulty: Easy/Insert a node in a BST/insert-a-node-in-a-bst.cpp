// Function to insert a node in a BST.

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* insert(Node* root, int key) {
        // Your code goes here
        if(root==NULL){
            root = new Node(key);
            return root;
        }
        Node* curr = root;
        while(curr!=NULL){
            if(curr->data> key){
                if(curr->left ==NULL) {
                    curr->left= new Node(key);
                    break;
                }
                else{
                curr = curr->left;
                }
            }
            
            else if(curr->data<key){
                if(curr->right==NULL){
                    curr->right = new Node(key);
                    break;
                }
                else{
                    curr= curr->right;
                }
            }
            else{
                break;
            }
        }
        return root;
    }
};