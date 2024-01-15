class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);

        unordered_map<int, int> win;
        unordered_map<int, int> lose;

        for(auto mat: matches) {
            win[ mat[0] ]++;
            lose[ mat[1] ]++;
        }

        for(auto winers: win) {
            if(lose[winers.first] == 0) {
                res[0].emplace_back(winers.first);
            }
        }

        for(auto loser: lose) {
            if(loser.second == 1) {
                res[1].emplace_back(loser.first);
            }
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};