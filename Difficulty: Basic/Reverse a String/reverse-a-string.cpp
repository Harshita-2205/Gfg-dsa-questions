// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }

        for(int i=0;i<s.size();i++){
            s[i]=st.top();
            st.pop();
        }
        return s;
        
        
    }
};
