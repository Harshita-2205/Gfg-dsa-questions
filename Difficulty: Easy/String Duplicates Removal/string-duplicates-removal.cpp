// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        vector<int> freq(256,0);
        string ans="";
        for(char i: s){
            if(freq[i]==0){
                ans.push_back(i);
                freq[i]++;
            }
        }
        return ans;
        
    }
};