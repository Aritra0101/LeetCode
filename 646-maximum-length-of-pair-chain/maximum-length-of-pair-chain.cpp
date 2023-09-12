class Solution {
private:
    bool static myCmp(vector<int>& a, vector<int> b) {
        return a[1] < b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), myCmp);

        for(const auto& it: pairs)
            cout<<it[0]<<" "<<it[1]<<endl;

        int res = 0;
        int prev = INT_MIN;
        for(const auto& it: pairs) {
            if(it[0] > prev) {
                res++;
                prev = it[1];
            }
        }
        return res;

        return 11;
    }
};