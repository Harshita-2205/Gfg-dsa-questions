class Solution {
  public:
 
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> unique_chars;

        // Initialize unique characters and indegree
        for (const string& word : words) {
            for (char c : word) {
                unique_chars.insert(c);
            }
        }
        for (char c : unique_chars) {
            indegree[c] = 0;
        }

        // Build the graph
        for (int i = 0; i < words.size() - 1; ++i) {
            const string& word1 = words[i];
            const string& word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            bool found = false;
            for (int j = 0; j < len; ++j) {
                char c1 = word1[j];
                char c2 = word2[j];
                if (c1 != c2) {
                    adj[c1].push_back(c2);
                    indegree[c2]++;
                    found = true;
                    break;
                }
            }
            // Handle cases like ["abc", "ab"] which is invalid
            if (!found && word1.size() > word2.size()) {
                return "";
            }
        }

        // Kahn's algorithm for topological sort
        queue<char> q;
        for (const auto& pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        string result;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            for (char neighbor : adj[c]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if all characters were included (no cycle)
        if (result.size() != unique_chars.size()) {
            return "";
        }

        return result;
    } 
};