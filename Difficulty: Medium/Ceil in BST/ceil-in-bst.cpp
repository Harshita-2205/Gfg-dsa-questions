/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    int Ceil = -1;
    while(root!=NULL){
        if(root->data == input){ 
            Ceil=root->data;
            return Ceil;
            
        }
        if(root->data < input){
            root = root->right;
           
        }
        else{
            Ceil = root->data;
             root=root->left;
        }
        }
    
    return Ceil;
    
}