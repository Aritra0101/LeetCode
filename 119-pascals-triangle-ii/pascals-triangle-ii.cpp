class Solution {
private:
    //nCr
    int pascalVal(int n, int r) {
        double ans = 1;
        for(int i=1; i<=r; i++)
            ans = ans * (n - r + i) / i;
        return int(ans);
    }

    vector<int> pascalTriangle01(int rowIndex) {
        vector<int> ans(rowIndex+1);
        for(int i=0; i<rowIndex+1; i++) {
            cout<<rowIndex<<' '<<i<<"   ";
            ans[i] = pascalVal(rowIndex, i);
        }
        return ans;
    }

public:
    vector<int> getRow(int rowIndex) {
        return pascalTriangle01(rowIndex);
        // return pascalTriangle02(rowIndex);
    }
};