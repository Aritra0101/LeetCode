class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int ind = 0;
        for(const auto& word: words) {
            if(word.find(x) != string::npos) {
                res.emplace_back(ind);
            }
            ind++;
        }

        return res;
    }
};