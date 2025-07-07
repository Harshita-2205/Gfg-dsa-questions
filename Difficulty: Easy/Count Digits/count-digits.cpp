class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        vector<int> ans;
        string num = to_string(n);
        int cnt = 0;
        for(char i: num){
            int t = i - '0';
            ans.push_back(t);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i] ==0){
                continue;
            }
            else if(n%ans[i]==0){
                cnt++;
            }
        }
        return cnt;
    }
};