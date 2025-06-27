class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n < 2) return -1; 
        sort(arr.begin(),arr.end());
        int num = arr[n-1];
    
        for (int i =n-2;i>=0;i--){
            if(arr[i] != num){
                return arr[i];
            }
        }
        return -1;
    }
};