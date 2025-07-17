class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int left = 0;
        int current_sum = 0;
        vector<int> result;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            if (current_sum == target) {
                result.push_back(left + 1); // 1-based indexing
                result.push_back(right + 1); // 1-based indexing
                return result;
            }
        }

        return {-1}; 
    }
};