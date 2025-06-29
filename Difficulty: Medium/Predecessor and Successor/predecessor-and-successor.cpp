/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* succ(Node* root,int key,vector<Node*> &ans){
        Node* succ = NULL;
        while(root!=NULL){
            if(root->data<=key){
                root = root->right;
            }
            else{
                succ = root;
                root=root->left;
            }
        }
        ans.push_back(succ);
        return succ;
    }
    Node* pre(Node* root,int key,vector<Node*> &ans){
        Node* pre = NULL;
        while(root!=NULL){
            if(root->data>=key){
                root=root->left;
            }
            else{
                pre=root;
                root=root->right;
            }
        }
        ans.push_back(pre);
        return pre;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        pre(root,key,ans);
        succ(root,key,ans);
        return ans;
    }
};