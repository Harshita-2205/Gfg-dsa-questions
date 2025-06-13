class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        stack<char> st;
        for(int i=0; i<s.size();i++){
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty() && i<s.size()){
            if (st.top()!=s[i]) return false;
            st.pop();
            i++;
        }
        return true;
        
    }
};