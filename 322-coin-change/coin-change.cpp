class Solution {
private:
    int solve01(vector<int>& coins, int amount, int i, int res) {
        if(i<0) {
            if(amount == 0) {
                return res;
            } else {
                return 1e7;
            }
        }

        if(amount == 0) {
            return  res;
        }

        int nonTake = solve01(coins, amount, i-1, res);
        int take = 1e7;
        if(amount >= coins[i]) {
            take = solve01(coins, amount-coins[i], i, res+1);
        }

        return min(nonTake, take);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // int res = solve01(coins, amount, n-1, 0);
        // return res==1e7 ? -1 : res;

        if(amount == 0) {
            return 0;
        }

        int n = coins.size();
        vector<int> dp(amount+1, amount+11);
        dp[0] = 0;

        for(int i=0; i<n; i++) { //coint
            for(int j=1; j<=amount; j++) { //amount
                if(j >= coins[i]) {
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
                }
            }
        }


        return dp[amount]==(amount+11)? -1 : dp[amount];
    }
};