class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int> duplicates;
        int n = arr.size();
        
        if (n == 0) {
            return {-1};
        }
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] == arr[i + 1]) {
                // To avoid adding the same duplicate multiple times
                if (duplicates.empty() || duplicates.back() != arr[i]) {
                    duplicates.push_back(arr[i]);
                }
                // Skip the next element as it's the same duplicate
                ++i;
            }
        }
        
        if (duplicates.empty()) {
            return {};
        }
        
        return duplicates;
    }
};