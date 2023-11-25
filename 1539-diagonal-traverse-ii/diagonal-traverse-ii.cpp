class Solution {
public:
    // vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    //     map<int, vector<int>> map;
    //     int n = nums.size(), m;
    //     for(int i=0; i<n; i++) {
    //         m = nums[i].size();
    //         for(int j=0; j<m; j++) {
    //             map[i+j].emplace_back(nums[i][j]);
    //         }
    //     }

    //     vector<int> res;
    //     for(auto it: map) {
    //         // copy(it.second.begin(), it.second.end(), back_inserter(res));
    //         res.insert(res.end(), it.second.rbegin(), it.second.rend()); 
    //     }
    //     return res;
    // }

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        queue<pair<int,int>> qu;
        qu.push( {0,0} );
        pair<int, int> p;

        while(!qu.empty()) {
            p = qu.front();
            qu.pop();

            res.emplace_back(nums[p.first][p.second]);

            if(p.second==0 && p.first+1 < n) {
                qu.push( {p.first+1, p.second} );
            }
            if(p.second+1 < nums[p.first].size()) {
                qu.push( {p.first, p.second+1} );
            }
        }
        return res; 
    }
};