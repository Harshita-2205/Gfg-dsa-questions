// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
          int n = arr.size();
        int ind = -1;
        
        // Step 1: Find the first element from the end that is smaller than its next element
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                ind = i;
                break;
            }
        }
        
        // If no such element is found, reverse the entire array
        if (ind == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        
        // Step 2: Find the smallest element greater than arr[ind] from the end
        for (int i = n - 1; i > ind; i--) {
            if (arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break; // Break after the first swap to ensure correctness
            }
        }
        
        // Step 3: Reverse the elements after ind to get the smallest lex order
        reverse(arr.begin() + ind + 1, arr.end());

        
    }
};