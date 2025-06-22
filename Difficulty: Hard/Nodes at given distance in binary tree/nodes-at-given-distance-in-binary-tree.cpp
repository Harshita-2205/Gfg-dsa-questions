/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
  
    void  markparents(Node* root,unordered_map<Node* ,Node* > &parent_track,Node* target_node){
        queue<Node* > q;
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
  
     Node* findTarget(Node* root, int target) {
        if (root == NULL) {
            return NULL;
        }
        
        if (root->data == target) {
            return root;
        }
        
        Node* leftResult = findTarget(root->left, target);
        if (leftResult != NULL) {
            return leftResult;
        }
        
        Node* rightResult = findTarget(root->right, target);
        return rightResult;
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        Node* target_node = findTarget(root,target);
        unordered_map<Node*,Node*> parent_track;
        markparents(root,parent_track,target_node);
        
        unordered_map<Node* ,bool> vis;
        queue<Node*> q;
        q.push(target_node);
        vis[target_node]=true;
        int curr_level=0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            res.push_back(curr->data);
        }
        sort(res.begin(), res.end());

        return res;
        
    }
    

        
};