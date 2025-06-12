// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        if(node==NULL){
            return ans;
        }
        
        stack<Node*> st1,st2;
        st1.push(node);
        while(!st1.empty()){
            node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!= NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
            
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }
};