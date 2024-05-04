class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();

        int l=0, r=n-1;
        int res = 0;
        while(l < r) {
            if(people[l] + people[r] <= limit) {
                res++;
                l++;
                r--;
            } else {
                res++;
                r--;
            }
        }

        if(l==r) res++;

        return res;
    }
};