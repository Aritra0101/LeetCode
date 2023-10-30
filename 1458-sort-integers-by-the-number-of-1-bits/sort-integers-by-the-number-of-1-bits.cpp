class Solution {
public:

    int countOne(int num) {
        int n=0;
        while(num) {
            if(num%2 == 1) n++;

            num /= 2;
        }
        return n;
    }
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        if(a.second == b.second)
            return (a.first < b.first);

        return (a.second < b.second);
    }

    vector<int> sortByBits(vector<int>& arr) {

        vector< pair<int, int> > ac;
        int n = arr.size();
        for(auto it: arr) {
            ac.emplace_back( make_pair(it, countOne(it)) );
        }

        sort(ac.begin(), ac.end(), sortbysec);

        for(int i=0; i<n; i++) {
            arr[i] = ac[i].first;
        }

        return arr;
    }
};