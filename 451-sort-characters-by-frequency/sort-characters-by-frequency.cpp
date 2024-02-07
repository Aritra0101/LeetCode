class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;

        for(char ch: s) {
            hash[ch]++;
        }

        priority_queue< pair<int, char>> pq;
        for(auto it: hash) {
            pq.push( make_pair(it.second, it.first) );
        }

        string res = "";
        while(!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();

            while(p.first--) {
                res += p.second;
            }
        }

        return res;
    }
};