class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 1;
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto [word, steps] = q.front(); q.pop();
            st.erase(word);
            
            if(word == endWord) {
                return steps;
            }

            for(int i=0; i<word.size(); i++) {
                char og = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)) {
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};
