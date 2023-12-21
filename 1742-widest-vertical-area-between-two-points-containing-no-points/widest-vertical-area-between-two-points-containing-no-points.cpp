class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int res = INT_MIN;

        sort(points.begin(), points.end());

        int n = points.size();
        for(int i=1; i<n; i++) {
            res = max(res, points[i][0]-points[i-1][0]);
        }

        return res;
    }
};