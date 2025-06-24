// User function template for C++

class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        if (a.size() != b.size()) {
            return false;
        }
        unordered_map<int,int> freq;
        for(int i=0;i<a.size();i++){
            freq[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(freq[b[i]]==0){
                return false;
            }
            freq[b[i]]--;
        }
        return true;
    }
};