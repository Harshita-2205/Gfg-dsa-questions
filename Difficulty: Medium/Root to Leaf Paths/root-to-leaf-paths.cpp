/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void pospaths(Node* node,vector<vector<int>> &ans,vector<int> &pa){
        if (node == NULL) {
            return;
        }
        
        pa.push_back(node->data);
        if(node->left==NULL && node->right==NULL){
            ans.push_back(pa);
        }
        else{
            pospaths(node->left,ans,pa);
            pospaths(node->right,ans,pa);
        }
        
        pa.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int>pa;
        if(root==NULL) return ans;
        pospaths(root,ans,pa);
        return ans;
    }
};