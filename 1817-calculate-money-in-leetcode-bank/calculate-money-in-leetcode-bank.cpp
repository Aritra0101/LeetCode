class Solution {
public:
    int totalMoney(int n) {
        int num = n;
        int res = 0;
        int base = 28;
        int bonus = 0;

        while(num >= 7) {
            res += base;
            res += (bonus * 7);

            num -= 7;
            bonus++;
        }

        res += ((num * (num + 1)) / 2);
        res += (bonus * num);
        return res;
    }
};