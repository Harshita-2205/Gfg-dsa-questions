class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(2);
        vector<int> vis(n+1,0);
        for(int i : arr){
            vis[i]++;
        }

        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                ans[1]=i;
            }
            if(vis[i]==2){
                ans[0]=i;
            }
        }
        return ans;
    }
};