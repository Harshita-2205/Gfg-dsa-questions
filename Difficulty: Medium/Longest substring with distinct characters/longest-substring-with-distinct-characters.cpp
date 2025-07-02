class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        if(n<=1) return n;
        int maxlen = 0;
        int l=0;
        int r=0;
        unordered_map<char,int> mpp;
        while(r<n){
            if(mpp.find(s[r]) != mpp.end()){
               l = max(l, mpp[s[r]] + 1);
            }
            int len = r-l+1;
            maxlen = max(maxlen,len);
            mpp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};
