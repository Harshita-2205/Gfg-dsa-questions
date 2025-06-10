class Solution {
  public:
  void rightEle(vector<int> &arr, vector<int> &rightSm, vector<int> &rightLrg){
        int n = arr.size();
        stack<int> stkSm, stkLrg;
        for(int i = n-1; i>=0; i--){
            while(!stkSm.empty() && arr[i]<=arr[stkSm.top()])
                stkSm.pop();
            rightSm[i] = stkSm.empty()?n:stkSm.top();
            stkSm.push(i);

            while(!stkLrg.empty() && arr[i]>=arr[stkLrg.top()])
                stkLrg.pop();
            rightLrg[i] = stkLrg.empty()?n:stkLrg.top();
            stkLrg.push(i);
        }
    }
    void leftEle(vector<int> &arr, vector<int> &leftSm, vector<int> &leftLrg){
        int n = arr.size();
        stack<int> stkSm, stkLrg;
        for(int i = 0; i<n; i++){
            while(!stkSm.empty() && arr[i]<arr[stkSm.top()])
                stkSm.pop();
            leftSm[i] = stkSm.empty()?-1:stkSm.top();
            stkSm.push(i);

            while(!stkLrg.empty() && arr[i]>arr[stkLrg.top()])
                stkLrg.pop();
            leftLrg[i] = stkLrg.empty()?-1:stkLrg.top();
            stkLrg.push(i);
        }
    }
 long long sumSubarrayMins(vector<int> &arr, vector<int> &leftSm, vector<int> &rightSm) {
        // code here
        int n = arr.size();

        long long ans = 0;
        int prev, next;
       
        for(int i = 0; i<n; i++){
            prev = i-leftSm[i];
            next = rightSm[i]-i;
       
            ans += (long long)prev*next*arr[i];
        }
        return ans;
    }
    long long sumSubarrayMax(vector<int> &arr, vector<int> &leftLrg, vector<int> &rightLrg){
        int n = arr.size();

        long long ans = 0;
        int prev, next;
       
        for(int i = 0; i<n; i++){
            prev = i-leftLrg[i];
            next = rightLrg[i]-i;
       
            ans += (long long)prev*next*arr[i];
        }
        return ans;
    }
      long long subarrayRanges(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> rightSm(n), rightLrg(n), leftSm(n), leftLrg(n);
       
        rightEle(arr, rightSm, rightLrg);
        leftEle(arr, leftSm, leftLrg);

        long long largest = sumSubarrayMax(arr, leftLrg, rightLrg);
        long long smallest = sumSubarrayMins(arr, leftSm, rightSm);

        return largest - smallest;
    }
};