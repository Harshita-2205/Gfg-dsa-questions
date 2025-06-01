// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &A) {
        int n = A.size();
        vector<int> pos, neg;
        
        // Segregate positive and negative numbers
        for (int num : A) {
            if (num >= 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }
        
        int i = 0, j = 0, k = 0;
        // Place positive and negative numbers alternately
        while (i < pos.size() && j < neg.size()) {
            A[k++] = pos[i++];
            A[k++] = neg[j++];
        }
        
        // Place remaining positive numbers
        while (i < pos.size()) {
            A[k++] = pos[i++];
        }
        
        // Place remaining negative numbers
        while (j < neg.size()) {
            A[k++] = neg[j++];
        }
    }
};