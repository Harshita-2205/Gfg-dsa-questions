/*Structure of the node of the binary tree is as
struct Node {
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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        
        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        
        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            vector<int> currentLevel(levelSize);
            
            for (int i = 0; i < levelSize; ++i) {
                Node* currentNode = nodesQueue.front();
                nodesQueue.pop();
                
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = currentNode->data;
                
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }
            
            for (int val : currentLevel) {
                result.push_back(val);
            }
            
            leftToRight = !leftToRight;
        }
        
        return result;
        
        
    }
};