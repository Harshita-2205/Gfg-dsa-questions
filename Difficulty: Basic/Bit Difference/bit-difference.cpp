//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countBitsFlip(int a, int b) {
        // code here
        int ans = a^b;
        int count = 0;
        for(int i =0;i<32;i++){
            if (ans&(1<<i)){
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
    int t;
    cin >> t;   // input the testcases
    while (t--) // while testcases exist
    {
        int a, b;
        cin >> a >> b; // input a and b

        Solution ob;
        cout << ob.countBitsFlip(a, b) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends