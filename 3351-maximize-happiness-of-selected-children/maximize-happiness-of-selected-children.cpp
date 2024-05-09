class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        int decrement = 0;
        long long res = 0;
        for(int i=0; i<k; i++) {
            if(decrement >= happiness[i]) {
                break;
            } else {
                res += (happiness[i] - decrement++);
            }
        }

        return res;
    }
};