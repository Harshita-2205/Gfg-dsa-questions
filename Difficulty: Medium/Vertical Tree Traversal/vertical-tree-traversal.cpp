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
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        if (!root) return {};
        
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            Node* node = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            nodes[x][y].push_back(node->data);
            
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& x_entry : nodes) {
            vector<int> vertical_line;
            for (auto& y_entry : x_entry.second) {
                vertical_line.insert(vertical_line.end(), y_entry.second.begin(), y_entry.second.end());
            }
            result.push_back(vertical_line);
        }
        
        return result;
        
    }
};