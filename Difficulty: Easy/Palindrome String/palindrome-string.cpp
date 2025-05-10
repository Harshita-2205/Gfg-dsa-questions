//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool Palindrome(int i,string& s) {
        // code here
        if (i>= s.size()/2){
            return true;
        }
        if (s[i]!= s[s.size()-i-1]){
            return false;
        }
        
        return Palindrome(i+1,s);
    }
        
        
  
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        return Palindrome(0,s);
        
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        string s;
        cin >> s; // Read the string

        Solution ob; // Create an instance of Solution
        if (ob.isPalindrome(s)) {
            cout << "true"; // Print true if palindrome
        } else {
            cout << "false"; // Print false if not a palindrome
        }
        cout << "\n~\n"; // Print newline after each result
    }

    return 0;
}

// } Driver Code Ends