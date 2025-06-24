class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
        int j=1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]!=arr[i+1]) j++;
        }
        unique(arr.begin(),arr.end());
        return j;
    }
};