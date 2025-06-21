/*  Structure of a Binary Tree

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
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        // Your code here
         if (root == NULL) {
            return 0;
        }
        
        queue<Node*> q;
        q.push(root);
        int max_width = 0;
        
        while (!q.empty()) {
            int level_size = q.size();
            max_width = max(max_width, level_size);
            
            for (int i = 0; i < level_size; ++i) {
                Node* current = q.front();
                q.pop();
                
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
        
        return max_width;
        
    }
};