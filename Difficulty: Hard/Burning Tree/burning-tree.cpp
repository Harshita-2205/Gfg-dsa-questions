/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void markparents(Node* root,unordered_map<Node*,Node*> &parent_track,Node* target_node){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
  
  
    Node* istarget(Node* root,int target){
        if (root==NULL){
            return NULL;
        }
        if(root->data==target){
            return root;
        }
        Node* left_res = istarget(root->left,target);
        if(left_res!=NULL) return left_res;
        
        Node* right_res = istarget(root->right,target);
        return right_res;
    
    }
    
    int minTime(Node* root, int target) {
        // code here
        Node* target_node = istarget(root,target);
        unordered_map<Node*,Node*> parent_track;
        markparents(root,parent_track,target_node);
        
        queue<Node*> q;
        unordered_map<Node*,int> vis;
        q.push(target_node);
        vis[target_node]= 1;
        int maxt = 0;
        while(!q.empty()){
            int size = q.size();
            int fl = 0;
            
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left]){
                    fl =1;
                    vis[curr->left]= 1;
                    q.push(curr->left);
                }
                if (curr->right && !vis[curr->right]){
                    fl =1;
                    vis[curr->right]= 1;
                    q.push(curr->right);
                }
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    fl=1;
                    vis[parent_track[curr]] = 1;
                    q.push(parent_track[curr]);
                }
            }
            if (fl) maxt++;
        }
        return maxt;
    }
};