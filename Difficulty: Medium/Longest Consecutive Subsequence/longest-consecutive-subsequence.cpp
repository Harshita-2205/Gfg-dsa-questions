class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& a) {
        // Your code here
        int longestseq = 1;
        int n = a.size();
        
        if(n==0) return 0;
        unordered_set<int> st;
        
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt =1;
                int x=it;
                while(st.find(x+1)!= st.end()){
                    x=x+1;
                    cnt = cnt+1;
                }
                longestseq = max(longestseq,cnt);
            }
        }
        
        return longestseq;
    }
};