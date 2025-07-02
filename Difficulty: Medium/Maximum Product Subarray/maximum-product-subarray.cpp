class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxpro = INT_MIN;
        int prefix = 1;
        int suffix=1;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            
            prefix = prefix*arr[i];
            suffix = suffix*arr[n-i-1];
            maxpro = max(maxpro,max(prefix,suffix));
        }
        return maxpro;
    }
};