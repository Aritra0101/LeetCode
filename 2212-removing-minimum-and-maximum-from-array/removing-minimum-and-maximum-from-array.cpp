class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 1;
        } else if(n <= 3) {
            return 2;
        }


        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        maxi += 1;
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        mini += 1;
        // cout<<maxi<<" "<<mini<<" - ";

        int left2right = max(maxi, mini);
        int right2left = n - min(maxi, mini) + 1;
        // cout<<left2right<<" "<<right2left;
        int side2side = min(maxi, mini) + n - max(maxi, mini) + 1;

        int res = min(side2side, min(left2right, right2left));

        return res;         
    }
};