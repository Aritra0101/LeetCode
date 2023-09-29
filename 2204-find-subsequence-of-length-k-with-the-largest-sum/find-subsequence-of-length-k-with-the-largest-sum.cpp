class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(int i=0; i<n; i++) {
            pq.push( make_pair(nums[i], i) );
        }

        while(pq.size() != k) {
            pq.pop();
        }

        vector<int> res(k);
        int i=0;
        while(!pq.empty()) {
            res[i++] = pq.top().second; 
            pq.pop();
        }

        sort(res.begin(), res.end());
        for(int i=0; i<k; i++) {
            res[i] = nums[ res[i] ];
        }

        return res;
    }
};