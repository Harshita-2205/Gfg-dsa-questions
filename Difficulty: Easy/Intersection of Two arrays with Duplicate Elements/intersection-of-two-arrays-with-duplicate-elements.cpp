class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> setB(b.begin(), b.end());
        vector<int> ans;
        
        for(num: setA){
            if(setB.count(num)){
                ans.push_back(num);
            }
        }

        return ans;
    }
};