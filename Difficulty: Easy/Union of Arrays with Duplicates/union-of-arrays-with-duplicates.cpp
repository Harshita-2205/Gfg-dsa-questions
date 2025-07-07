class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code 
        unordered_set<int> unionSet;
        vector<int> unionArr;
        
        // Insert all elements from both arrays into the set to avoid duplicates
        for (int num : a) {
            unionSet.insert(num);
        }
        for (int num : b) {
            unionSet.insert(num);
        }
        
        // Copy elements from the set to the vector
        for (int num : unionSet) {
            unionArr.push_back(num);
        }
        
        // Sort the vector to maintain order
        sort(unionArr.begin(), unionArr.end());
        
        return unionArr;
    }
};