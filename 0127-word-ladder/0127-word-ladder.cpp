class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //set of words
        //first word in the queue
        //change char , until word from wordlist found
        //continue and increase the levels accordingly 
        //do until endword found, return the count of levels

        queue<string>q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
        string word = q.front();
        q.pop();
        if(word == endWord)
            return level;

        for(int j = 0; j < word.length(); j++){
            char original = word[j];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[j] = ch;
                if(st.find(word) != st.end()){
                    q.push(word);
                    st.erase(word);
                }
            }
            word[j] = original;
        }
    }

    level++;
}
        return 0;
    }
};