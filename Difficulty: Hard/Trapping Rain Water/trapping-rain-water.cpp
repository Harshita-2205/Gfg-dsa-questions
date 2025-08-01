class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n<3) return 0;
        vector<int> left(n);
        vector<int> right(n);
        left[0]=arr[0];
        right[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            left[i]= max(left[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]= max(right[i+1],arr[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans= ans+ (min(left[i],right[i])-arr[i]) ;
        }
        return ans;
    }
};