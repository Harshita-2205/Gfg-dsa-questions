// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginword, string endword,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginword});
        vector<string> usedonlevel;
        usedonlevel.push_back(beginword);
        int level=0;
        vector<vector<string>> ans;
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            //erase all words that has been used at prev 
            if(vec.size()>level){
                level++;
                for(auto i : usedonlevel){
                    st.erase(i);
                }
            }
            string word = vec.back();
            if(word == endword){
                if(ans.size() ==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedonlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]= org;
            }
            
        }
        return ans;
    }
};