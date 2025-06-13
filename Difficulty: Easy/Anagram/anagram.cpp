class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int maxchar = 26;
        vector <int> freq(maxchar,0);
        
        for(char ch:s1){
            freq[ch-'a']++;
        }
        for(char ch:s2){
            freq[ch-'a']--;
        }
        for(int count:freq){
            if(count!=0) return false;
        }
        return true;
    }
};