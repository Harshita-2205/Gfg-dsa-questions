// User function template for C++

class Solution {
  public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string& s) {
        // your code here
        int maxchar = 26;
        vector<int> vis(maxchar,0);
        
        for(int i=0;i<s.size();i++){
            if('A'<=s[i] && s[i]<='Z'){
                vis[s[i]-'A']=true;
            }
            else if('a'<=s[i] && s[i]<='z'){
                vis[s[i]-'a']=true;
            }
        }
        for(int i=0;i<maxchar;i++){
            if(vis[i]==false) return false;
        }
        return true;
    }
};