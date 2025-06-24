/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    Node* buildtree(vector<int> &postorder,int poststart,int postend,vector<int> &inorder,int instart,int inend,map<int,int> &inmap){
       
        if(postend<poststart || instart>inend) return NULL;
        Node* root = new Node(postorder[postend]);
        int inroot = inmap[root->data];
        int numsleft = inroot-instart;
        
        root->left=buildtree(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,inmap);
        root->right=buildtree(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,inmap);
        
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        map<int, int> inmap;
        
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        
        Node* root = buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
        
        return root;
    }
};