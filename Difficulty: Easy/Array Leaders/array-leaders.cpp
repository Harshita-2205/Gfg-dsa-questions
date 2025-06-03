

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int maxele = INT_MIN;
        vector<int> ans;
        
        for(int i= arr.size()-1;i>=0;i--){
            if(arr[i]>=maxele){
                maxele= arr[i];
                ans.push_back(maxele);
            }
            
        };
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};