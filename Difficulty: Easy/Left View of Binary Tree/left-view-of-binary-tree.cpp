/* A binary tree node

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
    void lv(Node* root,int level,vector<int> &ans){
        if(root==NULL) return ;
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        lv(root->left,level+1,ans);
        lv(root->right,level+1,ans);
    }
    
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        lv(root,0,ans);
        return ans;
    }
};