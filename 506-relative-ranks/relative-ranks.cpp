class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> hashMap;
        priority_queue<int> pq;

        for(int n: score) {
            pq.push(n);
        }

        int rank = 1;
        while(!pq.empty()) {
            hashMap[ pq.top() ] = rank;
            rank++;
            pq.pop();
        }

        int n = score.size();
        vector<string> res(n);
        for(int i=0; i<n; i++) {
            if( hashMap[score[i]] == 1) {
                res[i] = "Gold Medal";
            } else if( hashMap[score[i]] == 2) {
                res[i] = "Silver Medal";
            } else if( hashMap[score[i]] == 3) {
                res[i] = "Bronze Medal";
            } else {
                res[i] = to_string(hashMap[score[i]]);
            }
        }

        return res;
    }
};