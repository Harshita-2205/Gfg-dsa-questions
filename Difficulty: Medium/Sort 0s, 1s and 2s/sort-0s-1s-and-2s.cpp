//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
         int arr1[]={0,0,0};
        for(int i=0;i<arr.size();i++){
            arr1[arr[i]]++;
        }
        int i;
        for(i=0;i<arr1[0];i++){
            arr[i]=0;
        }
        int j;
        for(j=i;j<arr1[1]+i;j++){
            arr[j]=1;
        }

        int k;
        for(k=j;k<arr1[2]+j;k++){
            arr[k]=2;
        }
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends