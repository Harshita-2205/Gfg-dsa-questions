class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        if(s.size()<=1) return s.size();
    
        vector<bool> vis(26,false) ;
        int maxlen = 0;
        int l = 0;
        int r=0;
        
        while(r<s.size()){
            while(vis[s[r]-'a'] == true){
                vis[s[l]-'a']= false;
                l++;
            }
            vis[s[r]-'a']= true;
            maxlen= max(maxlen, r-l+1);
            r++;
        }
        
        return maxlen;
    }

};
