// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(root==NULL) return 0;
    
    while(root!=NULL){
         if (root->data == x) return 1;
        if(root->data > x){
            root = root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
}