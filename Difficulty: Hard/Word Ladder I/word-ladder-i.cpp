class Solution {
  public:
    int wordLadderLength(string startword, string targetWord,
                         vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        q.push({startword,1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startword);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==targetWord) return steps;
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char j = 'a';j<='z';j++){
                    word[i] = j;
                    
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=org;
            }

        }
        return 0;
    }
};