// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(),arr.end());
        string first = arr.front();
        string last = arr.back();
        int minlen = min(first.size(),last.size());
        int i=0;
        while(i<minlen && first[i]==last[i]){
            i++;
        }
        return first.substr(0,i);
        
        
    }
};