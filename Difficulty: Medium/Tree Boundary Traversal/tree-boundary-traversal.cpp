/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    
  public:
  bool isleaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }
  void addleftnodes(Node* root,vector<int>& result){
        Node* cur =root->left;
        while (cur){
            if(!isleaf(cur)) result.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }

    }
    
    void addleafnodes(Node* root,vector<int>& result){
        if(isleaf(root)){
            result.push_back(root->data);
            return;
        }
        if(root->left) addleafnodes(root->left,result);
        if(root->right) addleafnodes(root->right,result);
    }
    
    void addrightnodes(Node* root,vector<int>& result){
        Node* cur = root->right;
        vector<int>temp;
        while(cur){
            if(!isleaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            result.push_back(temp[i]);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        if(root==NULL) return result;
        if(!isleaf(root)) result.push_back(root->data);
        
        addleftnodes(root,result);
        addleafnodes(root,result);
        addrightnodes(root,result);
        
        return result;
        
    }
    
  
};