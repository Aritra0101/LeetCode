class Solution {
private:
    //nCr
    int pascalVal(int n, int r) {
        // long long ans = 1;
        // for(int i=0; i<n-r; i++)
        //     ans *= n-i;
        // for(int i=n-r; i>1; i--)
        //     ans /= i;

        double ans = 1;
        for(int i=1; i<=r; i++)
            ans = ans * (n - r + i) / i;
        
        return int(ans);
    }
    vector<vector<int>> pascalTriangle01(int numRows) {
        vector<vector<int>> ans(numRows);
        cout<<pascalVal(3,1);

        for(int i=0; i<numRows; i++) {
            ans[i] = vector<int>(i+1, 11);
            for(int j=0; j<=i; j++) {
                cout<<i<<" "<<j<<"   ";
                ans[i][j] = pascalVal(i,j);
            }
            cout<<endl;
        }

        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        return pascalTriangle01(numRows);
    }
};