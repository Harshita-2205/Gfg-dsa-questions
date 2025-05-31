class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        // for positives and zeros
        int maxlen = 0;
       // int n = arr.size();
       // int i=0;
       // int j=0;
        long long sum = 0;
       // 
       // while(j<n){
       //     while(i<=j && sum>k){
       //         sum -= arr[i];
       //         i++;
       //     }
       //     if (sum==k){
       //         maxlen = max(maxlen , i-j +1);
       //     }
       //     j++;
       //     
       //     if(j<n ){
       //         sum+=arr[j];
       //     }
       // }
       // return maxlen;
       
       //now for negatives tooo
       map<long long, int> preSumMap;
       for (int i=0;i<arr.size();i++){
           sum += arr[i];
           if (sum == k){
               maxlen = max(maxlen, i+1);
           }
           long long rem = sum-k;
           if(preSumMap.find(rem)!= preSumMap.end()){
               int len = i-preSumMap[rem];
               maxlen = max(maxlen, len);
              
           }
           if(preSumMap.find(sum)== preSumMap.end()){
               preSumMap[sum] = i;
           }
       }
       return maxlen;
       
       
    }
};